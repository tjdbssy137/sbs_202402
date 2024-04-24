#include "pch.h"
#include "Pumpkin.h"
#include "BoxCollider.h"

void Pumpkin::Init()
{
	Super::Init();

	this->SetName("Pumpkin");

	Resource->LoadTexture(L"T_Pumpkin", L"Poo/pumpkin.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_Pumpkin", Resource->GetTexture(L"T_Pumpkin"));

	this->SetSprite(Resource->GetSprite(L"S_Pumpkin"));

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 45, 45));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, -50, 50, 50));
}
void Pumpkin::Render(HDC hdc)
{
	Super::Render(hdc);
}
void Pumpkin::Update()
{
	Super::Update();
	Move();
}
 void Pumpkin::Release()
{
	 Super::Release();
}

 void Pumpkin::Throw(float pPosX)
 {
	 _targetPos = Vector2(pPosX, 700);
	 this->SetBody(Shape::MakeCenterRect(pPosX, 0, 50, 50));
	 _moveDir = (_targetPos - _body.pos).Normalize();
 }
 void Pumpkin::Move()
 {
	 _body.pos += _moveDir * (Time->GetDeltaTime() * 500);
 }