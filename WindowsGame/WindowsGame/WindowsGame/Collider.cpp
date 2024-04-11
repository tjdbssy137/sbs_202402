#include "pch.h"
#include "Collider.h"

void Collider::Init()
{
	Super::Init();
	GET_SINGLE(CollisionManager)->AddCollider(this);
}
void Collider::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Collider::Update()
{
	Super::Update();
}
void Collider::Release()
{
	Super::Release();
	GET_SINGLE(CollisionManager)->RemoveCollider(this);
}

bool Collider::CheckCollision(Collider* other)
{
	return false;
}