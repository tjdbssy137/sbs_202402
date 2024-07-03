#include "pch.h"
#include "BulletActor.h"
#include "CircleCollider.h"
#include "Actor.h"
void BulletActor::Init()
{
	Super::Init();
	this->SetName("bullet");
	this->SetSprite(Resource->GetSprite(L"S_Bullet"));
	CircleCollider* collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), 5);
	collider->Init();
	collider->SetCollisionLayer(CollisionLayerType::CLT_ITEM);
	collider->ResetCollisionFlag();
	collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY);
	this->AddComponent(collider);
}
void BulletActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BulletActor::Update()
{
	Super::Update();
	Update_Move();
}
void BulletActor::Release()
{
	Super::Release();
}
void BulletActor::Update_Move()
{
	Vector2 dir = _targetBoat->GetPos() - this->GetPos();
	dir = dir.Normalize();
	_body.pos += dir * Time->GetDeltaTime() * _speed;
}
void BulletActor::ShootingBullet(Actor* targetBoat)
{
	if (targetBoat == nullptr)
	{
		return;
	}
	_targetBoat = targetBoat;
}