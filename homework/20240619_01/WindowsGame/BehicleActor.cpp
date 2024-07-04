#include "pch.h"
#include "BehicleActor.h"
#include "Dev2Scene.h"
#include "CircleCollider.h"
#include "BoatActor.h"
#include "BulletActor.h"
#include "BulletActorController.h"

void BehicleActor::Init()
{
	Super::Init();

	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eDirection::END; i++)
	{
		_idleFlipbook[i] = Resource->GetFlipbook(GetBehicleType() + direction[i]);
	}
	this->SetName("behicle_site");
	this->SetState(_state);

	collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), 200);
	collider->Init();
	collider->SetCollisionLayer(CollisionLayerType::CLT_BEHICLE);
	collider->ResetCollisionFlag();
	collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY); // 충돌할 레이어

	this->AddComponent(collider);

	{
		Dev2Scene* dev2Scene = static_cast<Dev2Scene*>(CurrentScene);
		_bulletActorController = dev2Scene->GetBulletActorController();
	}
}
void BehicleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BehicleActor::Update()
{
	Super::Update();

	// XXX : <- 이슈 위험
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
	//FSM 유한상태머신

	_state = state;

	this->SetFlipbook(_idleFlipbook[_dir]);
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
	Dev2Scene* dev2Scene = static_cast<Dev2Scene*>(CurrentScene);
	vector<BoatActor*> boats = dev2Scene->GetBoatActor();

	//공격을실행할거다.
	for (BoatActor* boat : boats)
	{
		if (Collision::CircleInCircle(this->GetPos(), collider->GetRadius(),
			boat->GetPos(), boat->GetBoatCollider()->GetRadius()))
		{
			// 왜 한 영역에 들어가면 걔 판정만 받는지? 여러 개의 공격을 받아야하는데
			_targetBoat = boat;
			_state = BehicleState::Attack;
		}
	};

	// 1초에 한번씩 공격할말을 결정
	// 공격하기로 결정했을 때 내 바운더리 안에 있으면 공격.
	// 만약 적이 너무 많이 오면 순서를..
}

void BehicleActor::UpdateAttack()
{
	LookAtTarget();
	static float lastTick = ::GetTickCount64();
	float currentTick = ::GetTickCount64();
	if (_time < currentTick - lastTick) // 1초에 한번씩 공격할말을 결정
	{
		LoadBullet();
		lastTick = currentTick;
	}
}

void BehicleActor::LookAtTarget() // target을 바라보기
{
	// target은 가장 가까운 거리에 있는 애 바라보는 걸로
	Vector2 dirVec = _targetBoat->GetPos() - this->GetPos();
	dirVec = dirVec.Normalize();
	
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

	if (maxDotValue < rightDotValue) {
		maxDotValue = rightDotValue;
		direction = eDirection::RIGHT;
	}

	if (maxDotValue < downDotValue) {
		maxDotValue = downDotValue;
		direction = eDirection::DOWN;
	}

	if (maxDotValue < leftDotValue) {
		maxDotValue = leftDotValue;
		direction = eDirection::LEFT;
	}

	if (maxDotValue < upRightDotValue) {
		maxDotValue = upRightDotValue;
		direction = eDirection::UP_RIGHT;
	}

	if (maxDotValue < upLeftDotValue) {
		maxDotValue = upLeftDotValue;
		direction = eDirection::UP_LEFT;
	}

	if (maxDotValue < downRightDotValue) {
		maxDotValue = downRightDotValue;
		direction = eDirection::DOWN_RIGHT;
	}

	if (maxDotValue < downLeftDotValue) {
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