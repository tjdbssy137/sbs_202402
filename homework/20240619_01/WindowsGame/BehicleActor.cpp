#include "pch.h"
#include "BehicleActor.h"
#include "Dev2Scene.h"
#include "CircleCollider.h"
#include "BoatActor.h"
#include "BulletActor.h"
#include "BulletActorController.h"
#include "BehicleController.h"
void BehicleActor::Init()
{
	this->SetState(_state);

	collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), _colliderSize);
	collider->Init();
	collider->SetCollisionLayer(CollisionLayerType::CLT_BEHICLE);
	collider->ResetCollisionFlag();
	collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY); // �浹�� ���̾�

	//this->SetActiveBehicle();
	this->AddComponent(collider);

	{
		Dev2Scene* dev2Scene = static_cast<Dev2Scene*>(CurrentScene);
		_bulletActorController = dev2Scene->GetBulletActorController();
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

	// XXX : <- �̽� ����
	switch (_state)
	{
	case BehicleState::Attack:
	{
		LookAtTarget();
		UpdateAttack();
	}
	break;
	case BehicleState::Submarine:
		LookAtTarget();
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
//		wcout << GetBehicleType() << endl;
	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eDirection::END; i++)
	{
		_idleFlipbook[i] = Resource->GetFlipbook(GetBehicleType() + direction[i]);
	}
	this->ChangeDirection(eDirection::DOWN);

	if (this->GetBehicleType() == L"FB_Submarine_")
	{
		collider->SetCollision(Vector2::Zero(), 0);
	}
	else
	{
		collider->SetCollision(Vector2::Zero(), _colliderSize);
		_time = _attackTime;
	}

}
void BehicleActor::SetState(BehicleState state)
{
	//FSM ���ѻ��¸ӽ�

	_state = state;

	//this->SetFlipbook(_idleFlipbook[_dir]);
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
	Dev2Scene* dev2Scene = static_cast<Dev2Scene*>(CurrentScene);
	vector<BoatActor*> boats = dev2Scene->GetBoatActor();

	//�����������ҰŴ�.
	for (BoatActor* boat : boats)
	{
		if (Collision::CircleInCircle(this->GetPos(), collider->GetRadius(),
			boat->GetPos(), boat->GetBoatCollider()->GetRadius()))
		{
			_targetBoat = boat;
			if (this->GetBehicleType() == L"FB_Submarine_")
			{
				_state = BehicleState::Submarine;
			}
			else
			{
				_state = BehicleState::Attack;
			}
		}
	};

	// 1�ʿ� �ѹ��� �����Ҹ��� ����
	// �����ϱ�� �������� �� �� �ٿ���� �ȿ� ������ ����.
	// ���� ���� �ʹ� ���� ���� ������..
}

void BehicleActor::UpdateAttack()
{
	_time -= Time->GetDeltaTime();
	//static float lastTick = ::GetTickCount64(); //��� ȣ�⿡�� ����
	//float currentTick = ::GetTickCount64();
	if (_time <= 0) // 1�ʿ� �ѹ��� �����Ҹ��� ����
	{
		LoadBullet();
		_time = _attackTime;
	}
}

void BehicleActor::LookAtTarget() // target�� �ٶ󺸱�
{
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
void BehicleActor::LoadBullet()
{
	if (_bulletActorController->BulletCount() < 30)
	{
		BulletActor* bullet = new BulletActor();
		bullet->SetLayer(LayerType::Object);
		bullet->SetPos(this->GetPos());
		Dev2Scene* dev2Scene = static_cast<Dev2Scene*>(CurrentScene);
		bullet->Init();
		dev2Scene->SpawnActor(bullet);
		bullet->SetBulletDamage(_behicleBulletDamage);
		bullet->SetBulletSpeed(_behicleBulletSpeed);
		bullet->SetATarget(_targetBoat);
		_bulletActorController->PushBullet(bullet);
	}
	else
	{
		BulletActor* bullet = _bulletActorController->PopBullet();
		bullet->SetPos(this->GetPos());
		bullet->SetBulletDamage(_behicleBulletDamage);
		bullet->SetBulletSpeed(_behicleBulletSpeed);
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