#include "pch.h"
#include "BrickActor.h"

#include "BoxCollider.h"
void BrickActor::Init()
{
	Super::Init();
	this->SetName("Brick");
	this->SetBody(Shape::MakeCenterRect(0, 0, 100, 40));
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 40));
	this->AddComponent(collider);
}
void BrickActor::Render(HDC hdc)
{
	Super::Render(hdc);
	_body.Draw(hdc);
}
void BrickActor::Update()
{
	Super::Update();
}
void BrickActor::Release()
{
	Super::Release();
}