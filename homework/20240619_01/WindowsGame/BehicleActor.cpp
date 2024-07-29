#include "pch.h"
#include "BehicleActor.h"
#include "TowerDefenseScene.h"
#include "CircleCollider.h"
#include "BoatActor.h"
#include "BulletActor.h"
#include "BulletActorController.h"
#include "BehicleController.h"

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

	{
		TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
		_bulletActorController = towerDefenseScene->GetBulletActorController();
		_boats = towerDefenseScene->GetBoatActor();
	}
	Super::Init();
}
void BehicleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BehicleActor::Update()
{
	Super::Update();
	LookAtTarget();

	// XXX : <- �̽� ����
	switch (_state)
	{
	case BehicleState::Attack:
	{
		UpdateAttack();
	}
	break;
	case BehicleState::Submarine:
		break;
	case BehicleState::Idle:
		UpdateIdle();
		break;
	case BehicleState::None:
		break;
	default:
		break;
	}
}

void BehicleActor::Release()
{
	Super::Release();
}
void BehicleActor::SetActiveBehicle()
{
	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	
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
		_time = _data.AttackTime;
	}
}

void BehicleActor::ChangeDirection(eDirection dir)
{
	// ���࿡ ������ �ٲ��, setFlipbook�� ���ش�/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_idleFlipbook[_dir]);
}

void BehicleActor::UpdateIdle()
{
	//���� �ȿ� ������ ������ �����ҰŴ�.
	for (BoatActor* boat : _boats)
	{
		// �����ϱ�� �������� �� �� �ٿ���� �ȿ� ������ ����.
		if (Collision::CircleInCircle(this->GetPos(), _collider->GetRadius(),
			boat->GetPos(), boat->GetBoatCollider()->GetRadius()))
		{
			_targetBoat = boat;
			if (_targetBoat->GetBoatHp() <= 0)
			{
				continue;
			}
			
			if (_data.Id == 7)
			{
				_state = BehicleState::Submarine;
			}
			else
			{
				_state = BehicleState::Attack;
			}
		}
	};
}

void BehicleActor::UpdateAttack()
{
	_time -= Time->GetDeltaTime();
	//static float lastTick = ::GetTickCount64(); //��� ȣ�⿡�� ����
	//float currentTick = ::GetTickCount64();
	if (_time <= 0) // 1�ʿ� �ѹ��� �����Ҹ��� ����
	{
		UseBullet();
		_time = _data.AttackTime;
	}
}

void BehicleActor::LookAtTarget() // target�� �ٶ󺸱�
{
	if (_targetBoat == nullptr)
	{
		return;
	}
	Vector2 dirVec = _targetBoat->GetPos() - this->GetPos();
	dirVec = dirVec.Normalize();
	
	if (200 < dirVec.LengthSqrt()) // ���� �Ÿ� �̻� �Ѿ�� ����
	{
		_state = BehicleState::Idle;
	}

	float upDotValue = dirVec.Dot(Vector2::Up());
	float rightDotValue = dirVec.Dot(Vector2::Right());
	float downDotValue = dirVec.Dot(Vector2::Down());
	float leftDotValue = dirVec.Dot(Vector2::Left());
	float upRightDotValue = dirVec.Dot(Vector2::UpNRight());
	float upLeftDotValue = dirVec.Dot(Vector2::UpNLeft());
	float downRightDotValue = dirVec.Dot(Vector2::DownNRight());
	float downLeftDotValue = dirVec.Dot(Vector2::DownNLeft());

	float maxDotValue = upDotValue;
	eDirection direction = eDirection::UP;

	if (maxDotValue < rightDotValue) 
	{
		maxDotValue = rightDotValue;
		direction = eDirection::RIGHT;
	}

	if (maxDotValue < downDotValue) 
	{
		maxDotValue = downDotValue;
		direction = eDirection::DOWN;
	}

	if (maxDotValue < leftDotValue) 
	{
		maxDotValue = leftDotValue;
		direction = eDirection::LEFT;
	}

	if (maxDotValue < upRightDotValue) 
	{
		maxDotValue = upRightDotValue;
		direction = eDirection::UP_RIGHT;
	}

	if (maxDotValue < upLeftDotValue) 
	{
		maxDotValue = upLeftDotValue;
		direction = eDirection::UP_LEFT;
	}

	if (maxDotValue < downRightDotValue) 
	{
		maxDotValue = downRightDotValue;
		direction = eDirection::DOWN_RIGHT;
	}

	if (maxDotValue < downLeftDotValue) 
	{
		maxDotValue = downLeftDotValue;
		direction = eDirection::DOWN_LEFT;
	}

	this->ChangeDirection(direction);
}
void BehicleActor::UseBullet()
{
	if (_bulletActorController->BulletCount() < 1) // ������ �����ϰ� ���� ���� -> �̹� BulletActorController ���⼭ �ϰ� ����
	{
		BulletActor* bullet = new BulletActor();
		bullet->SetLayer(LayerType::Object);
		bullet->SetPos(this->GetPos());
		TowerDefenseScene* towerDefenseScene = static_cast<TowerDefenseScene*>(CurrentScene);
		bullet->Init();
		towerDefenseScene->SpawnActor(bullet);
		bullet->SetBulletDamage(_data.BulletDamage);
		bullet->SetBulletSpeed(_data.BulletSpeed);

		bullet->SetATarget(_targetBoat);
		_bulletActorController->PushBullet(bullet);
	}
	else
	{
		BulletActor* bullet = _bulletActorController->PopBullet();
		bullet->SetPos(this->GetPos());
		bullet->SetBulletDamage(_data.BulletDamage);
		bullet->SetBulletSpeed(_data.BulletSpeed);
		bullet->SetATarget(_targetBoat);
	}
	_state = BehicleState::Idle;
	
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
