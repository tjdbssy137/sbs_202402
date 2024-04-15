#include "pch.h"
#include "BrickActor.h"

#include "BoxCollider.h"
void BrickActor::Init()
{
	Super::Init();
	this->SetName("Brick");
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 100, 40));
	this->AddComponent(collider);

	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, 30, 100, 40));

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