#include "pch.h"
#include "BulletActor.h"
#include "CircleCollider.h"
void BulletActor::Init()
{
	Super::Init();
	this->SetName("bullet");
	this->SetSprite(Resource->GetSprite(L"S_Bullet"));
	CircleCollider* collider = new CircleCollider();
	collider->SetCollision(Vector2::Zero(), 32);
	collider->Init();
	collider->SetCollisionLayer(CollisionLayerType::CLT_ITEM);
	collider->ResetCollisionFlag();
	collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ENEMY);
}
void BulletActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void BulletActor::Update()
{
	Super::Update();
}
void BulletActor::Release()
{
	Super::Release();
}
void BulletActor::ShootingBullet(Vector2 moveDir)
{
	if (moveDir.Length() == 0.0f)
	{
		return;
	}
	if (moveDir.y != 0)
	{
		moveDir.y = 0;
		moveDir = moveDir.Normalize();
	}

	_body.pos += moveDir * Time->GetDeltaTime() * _speed;

	// 몇초뒤에 위치 다시 설정
}