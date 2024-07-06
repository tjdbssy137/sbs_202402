#include "pch.h"
#include "SubmarineActor.h"
#include "Dev2Scene.h"
#include "CircleCollider.h"

void SubmarineActor::Init()
{
	wstring direction[eDirection::END]
		= { L"Down", L"Left", L"Right", L"Up", L"DownNLeft", L"DownNRight", L"UpNLeft", L"UpNRight" };
	for (int i = 0; i < eDirection::END; i++)
	{
		_idleFlipbook[i] = Resource->GetFlipbook(L"FB_Submarine_" + direction[i]);
	}

	CircleCollider* collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), 10);
	collider->Init();
	collider->SetCollisionLayer(CollisionLayerType::CLT_BEHICLE);
	collider->ResetCollisionFlag();
	collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY); // 충돌할 레이어
	Super::Init();
}
void SubmarineActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void SubmarineActor::Update()
{
	Super::Update();
	switch (_state)
	{
	case BehicleState::Attack:
		LookAtTarget();
		break;
	case BehicleState::Idle:
		UpdateIdle();
		break;
	default:
		break;
	}
}

void SubmarineActor::Release()
{
	Super::Release();
}
void SubmarineActor::SetCellPos(Vector2Int cellPos, bool teleport)
{
	_cellPos = cellPos;
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);

	if (scene == nullptr)
	{
		return;
	}
	Vector2 destPos = scene->GetTilemapPos(cellPos);
	_destPos = destPos;
	if (teleport)
	{
		this->SetPos(_destPos);
	}
}
Vector2Int SubmarineActor::GetCellPos()
{
	return _cellPos;
}