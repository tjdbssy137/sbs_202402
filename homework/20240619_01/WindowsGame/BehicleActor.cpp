#include "pch.h"
#include "BehicleActor.h"
#include "TowerDefenseScene.h"
#include "CircleCollider.h"
#include "BoatActor.h"

void BehicleActor::Init()
{
	this->SetState(_state);

	_collider = new CircleCollider();
	_collider->SetCollision(Vector2::Zero(), 0);
	_collider->Init();
	_collider->SetCollisionLayer(CollisionLayerType::CLT_BEHICLE);
	_collider->ResetCollisionFlag();
	_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY); // �浹�� ���̾�

	this->AddComponent(_collider);

	Super::Init();
}
void BehicleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BehicleActor::Update()
{
	Super::Update();
}

void BehicleActor::Release()
{
	Super::Release();
}
void BehicleActor::SetActiveBehicle()
{
	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	cout << _data.Name << endl;
	wstring name = wstring().assign(_data.Name.begin(), _data.Name.end());
	for (int i = 0; i < eDirection::END; i++)
	{
		_idleFlipbook[i] = Resource->GetFlipbook(name + direction[i]);
	}
	this->ChangeDirection(eDirection::DOWN);

	if (_data.Id == 7)
	{
		_collider->SetCollision(Vector2::Zero(), 0);
	}
	else
	{
		_collider->SetCollision(Vector2::Zero(), _data.ColliderSize); // ���⼭ nullptr���� ��.
		//_time = _data.AttackTime; // ó���� ������ ���� �ٷ� ����
	}
}

void BehicleActor::ChangeDirection(eDirection dir)
{
	// ���࿡ ������ �ٲ��, setFlipbook�� ���ش�/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_idleFlipbook[_dir]);
}

void BehicleActor::LookAtTarget() // target�� �ٶ󺸱�
{
	
	if (this == nullptr)
	{
		return;
	}
	if (_targetBoat == nullptr)
	{
		return;
	}

	Vector2 dirVec = _targetBoat->GetPos() - this->GetPos();

	if (50 + (_data.ColliderSize * _data.ColliderSize) < dirVec.LengthSqrt()) // ���� �Ÿ� �̻� �Ѿ�� ����
	{
		_targetBoat = nullptr;
		_state = BehicleState::Idle;
		return;
	}
	
	dirVec = dirVec.Normalize();

	float angle = Vector2::SignedAngle(Vector2::Up(), dirVec);
	eDirection direction = eDirection::UP;

	if (-22.5f <= angle && angle < 22.5f)
	{
		direction = eDirection::UP;
	}
	else if (22.5 <= angle && angle < 67.5f)
	{
		direction = eDirection::UP_RIGHT;
	}
	else if (67.5f <= angle && angle < 112.5f)
	{
		direction = eDirection::RIGHT;
	}
	else if (112.5f <= angle && angle < 157.5f)
	{
		direction = eDirection::DOWN_RIGHT;
	}
	else if (157.5f <= angle || angle < -157.5f)
	{
		direction = eDirection::DOWN;
	}
	else if (-157.5f <= angle && angle < -112.5f)
	{
		direction = eDirection::DOWN_LEFT;
	}
	else if (-112.5f <= angle && angle < -67.5f)
	{
		direction = eDirection::LEFT;
	}
	else if (-67.5f <= angle && angle < -22.5f)
	{
		direction = eDirection::UP_LEFT;
	}

	this->ChangeDirection(direction);
}

void BehicleActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;
	//_destPos�� ��Ȯ�ϰ� ¤���� ��
	// ���� �ʿ� �ִ� Tilemap�� �ҷ��ͼ� �ش� ���� �ִ� 
	// _destPos = Tile ��ǥ�� �����´�.

	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	// �̷л� ���� Ÿ�ϸ��� �ֱ⿡ ���� ������ �� �־�� ��.
	// Ư�� Ŭ������ Actor���� ���� �ְų� ��򰡿� �ִ� ���𰡸� ���;��ϴ� ��Ȳ�� �ǰ� ���� �߻�
	// �׶� �� �������� ������ �Ұ���.
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;

	// �ڿ������� �̵��ؼ� �� ���������� ��������, �����̵� ���Ѽ� 1�����Ӹ�(���)�� �̵���ų ���̳�.
	if (teleport)
	{
		this->SetPos(_destPos);
	}
}
Vector2Int BehicleActor::GetCellPos()
{
	return _cellPos;
}