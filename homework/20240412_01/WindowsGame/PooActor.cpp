#include "pch.h"
#include "PooActor.h"
#include "BoxCollider.h"

void PooActor::Init()
{
	Super::Init();
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 50, 50));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X/2, -50, 50, 50));
}
void PooActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void PooActor::Update()
{
	Super::Update();
	//this->Move();
}
void PooActor::Release()
{
	Super::Release();
}

void PooActor::Throw(float pPosX, float pPosY)
{
	_targetPos = Vector2(pPosX, 700);
	this->SetBody(Shape::MakeCenterRect(pPosX, 0, 50, 50));
	_moveDir = (_targetPos - _body.pos).Normalize();
}
void PooActor::Move()
{
	_body.pos += _moveDir * (Time->GetDeltaTime() * 500);
}