#include "pch.h"
#include "BehicleActor.h"
#include "Dev2Scene.h"

void BehicleActor::Init()
{
	Super::Init();

	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eDirection::END; i++)
	{
		_idleFlipbook[i] = Resource->GetFlipbook(GetBehicleType() + direction[i]);
	}

	this->SetState(_state);
}
void BehicleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BehicleActor::Update()
{
	Super::Update();

	// XXX : <- �̽� ����
	switch (_state)
	{
	case BehicleState::Attack:
		UpdateAttack();
		break;
	case BehicleState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}
}

void BehicleActor::Release()
{
	Super::Release();
}

void BehicleActor::SetState(BehicleState state)
{
	//FSM ���ѻ��¸ӽ�

	_state = state;

	this->SetFlipbook(_idleFlipbook[_dir]);
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
	
}

void BehicleActor::UpdateAttack()
{
	Vector2 dirVec = _targetPos - this->GetPos();
	dirVec = dirVec.Normalize();
	

}

void BehicleActor::LookAtTarget() // target�� �ٶ󺸱�
{
	// target�� ���� ����� �Ÿ��� �ִ� �� �ٶ󺸴� �ɷ�.
	// ������ �� �޾ƿͼ� ������� �Ÿ��� ���?
	// �ݶ��̴� ���?
	Vector2 dirVec = _targetPos - this->GetPos();
	dirVec = dirVec.Normalize();
	
	Vector2 directions[eDirection::END] =
	{
		Vector2::Up(),				// UP
		Vector2::Right(),			// RIGHT
		Vector2::Down(),			// DOWN
		Vector2::Left(),			// LEFT
		Vector2::UpNLeft(),			// UP_RIGHT
		Vector2::UpNRight(),		// DOWN_RIGHT
		Vector2::DownNLeft(),		// DOWN_LEFT
		Vector2::DownNRight()		// UP_LEFT
	};

	float dotValues[eDirection::END];
	for (int i = 0; i < eDirection::END; i++) {
		dotValues[i] = dirVec.Dot(directions[i]);
	}

	// �ִ� �� ã��
	int targetDir = 0;
	float cos45 = cos(Deg2Rad(45));
	for (int i = 0; i < eDirection::END; i++) {
		if (cos45 < dotValues[i]) {
			targetDir = i;
		}
	}

	switch (targetDir) {
	case 0:
		this->ChangeDirection(eDirection::UP);
		break;
	case 1:
		this->ChangeDirection(eDirection::RIGHT);
		break;
	case 2:
		this->ChangeDirection(eDirection::DOWN);
		break;
	case 3:
		this->ChangeDirection(eDirection::LEFT);
		break;
	case 4:
		this->ChangeDirection(eDirection::UP_LEFT);
		break;
	case 5:
		this->ChangeDirection(eDirection::UP_RIGHT);
		break;
	case 6:
		this->ChangeDirection(eDirection::DOWN_LEFT);
		break;
	case 7:
		this->ChangeDirection(eDirection::DOWN_RIGHT);
		break;
	}
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