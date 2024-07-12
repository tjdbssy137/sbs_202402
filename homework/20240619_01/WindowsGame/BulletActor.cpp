#include "pch.h"
#include "BulletActor.h"
#include "CircleCollider.h"
#include "BoatActor.h"
#include "BulletActorController.h"
#include "Dev2Scene.h"

void BulletActor::Init()
{
	this->SetName("bullet");
	this->SetSprite(Resource->GetSprite(L"S_Bullet"));
	CircleCollider* collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), 5);
	collider->Init();
	collider->SetCollisionLayer(CollisionLayerType::CLT_ITEM);
	collider->ResetCollisionFlag();
	collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY);
	this->AddComponent(collider);
	
	{
		Dev2Scene* dev2Scene = static_cast<Dev2Scene*>(CurrentScene);
		_bulletActorController = dev2Scene->GetBulletActorController();
	}
	Super::Init();
}
void BulletActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BulletActor::Update()
{
	Super::Update();
	switch (_state)
	{
	case BulletState::Move:
		Update_Move();
		break;
	case BulletState::Done:
	{
		this->SetPos({ 2000, 2000 });
	}
		break;
	default:
		break;
	}
}
void BulletActor::Release()
{
	Super::Release();
}
void BulletActor::Update_Move()
{
	if (_targetBoat->GetState() == BoatState::Move || _targetBoat->GetState() == BoatState::Idle) // Á×¾úÀ» ¶§ 
	{
		Vector2 dir = _targetBoat->GetPos() - this->GetPos();
		dir = dir.Normalize();
		_body.pos += dir * Time->GetDeltaTime() * _speed;
	}
	else
	{
		_state = BulletState::Done;
		_bulletActorController->PushBullet(this);
	}
}
void BulletActor::SetATarget(BoatActor* targetBoat)
{
	if (targetBoat == nullptr)
	{
		return;
	}
	_targetBoat = targetBoat;
	_state = BulletState::Move;
}