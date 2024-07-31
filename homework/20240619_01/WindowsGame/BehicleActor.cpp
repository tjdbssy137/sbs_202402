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
	_collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY); // 충돌할 레이어

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

	// XXX : <- 이슈 위험
	switch (_state)
	{
	case BehicleState::Attack:
		UpdateAttack();
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
		_collider->SetCollision(Vector2::Zero(), _data.ColliderSize); // 여기서 nullptr값이 됨.
		//_time = _data.AttackTime; // 처음엔 딜레이 없이 바로 공격
	}
}

void BehicleActor::ChangeDirection(eDirection dir)
{
	// 만약에 방향이 바뀌면, setFlipbook을 해준다/

	if (_dir == dir) return;

	_dir = dir;
	this->SetFlipbook(_idleFlipbook[_dir]);
}

void BehicleActor::UpdateIdle()
{
	//범위 안에 들어오면 공격을 실행할거다.
	for (BoatActor* boat : _boats)
	{
		// 공격하기로 결정했을 때 내 바운더리 안에 있으면 공격.
		if (Collision::CircleInCircle(this->GetPos(), _collider->GetRadius(),
			boat->GetPos(), boat->GetBoatCollider()->GetRadius()))
		{
			_targetBoat = boat;
			if (_targetBoat->GetBoatHp() <= 0)
			{
				continue;
			}
			
			if (_data.Id != 7)
			{
				_state = BehicleState::Attack;
			}
			else
			{
				_state = BehicleState::Submarine; //return;
			}
		}
	};
}

void BehicleActor::UpdateAttack()
{
	_time -= Time->GetDeltaTime();
	//static float lastTick = ::GetTickCount64(); //모든 호출에서 공유
	//float currentTick = ::GetTickCount64();
	if (_time <= 0) // AttackTime마다 한번씩 공격할말을 결정
	{
		UseBullet();
		_time = _data.AttackTime;
	}
}

void BehicleActor::LookAtTarget() // target을 바라보기
{
	if (_targetBoat == nullptr)
	{
		return;
	}
	
	Vector2 dirVec = _targetBoat->GetPos() - this->GetPos();

	if (50 + (_data.ColliderSize * _data.ColliderSize) < dirVec.LengthSqrt()) // 일정 거리 이상 넘어가면 포기
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
void BehicleActor::UseBullet()
{
	if (_bulletActorController->BulletCount() < 1) // 씬에서 생성하고 꺼내 쓰기 -> 이미 BulletActorController 여기서 하고 있음
	{
		BulletActor* bullet = new BulletActor();
		bullet->SetLayer(LayerType::Object);
		bullet->SetPos(this->GetPos());
		bullet->Init();
		CurrentScene->SpawnActor(bullet);
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
	//_destPos를 정확하게 짚어줄 것
	// 현재 맵에 있는 Tilemap을 불러와서 해당 셀에 있는 
	// _destPos = Tile 좌표를 가져온다.

	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	// 이론상 씬에 타일맵이 있기에 값을 가져올 수 있어야 함.
	// 특정 클래스나 Actor에서 씬에 있거나 어딘가에 있는 무언가를 들고와야하는 상황이 되게 자주 발생
	// 그때 못 가져오면 개발이 불가능.
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;

	// 자연스럽게 이동해서 저 포지션으로 갈것인지, 순간이동 시켜서 1프레임만(즉시)에 이동시킬 것이냐.
	if (teleport)
	{
		this->SetPos(_destPos);
	}
}
Vector2Int BehicleActor::GetCellPos()
{
	return _cellPos;
}
