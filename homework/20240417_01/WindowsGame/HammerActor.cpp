#include "pch.h"
#include "HammerActor.h"
#include "BoxCollider.h"

void HammerActor::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Hammer_00", L"Mole/hammer_00.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_Hammer_00", Resource->GetTexture(L"T_Hammer_00"));

	Resource->LoadTexture(L"T_Hammer_01", L"Mole/hammer_01.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_Hammer_01", Resource->GetTexture(L"T_Hammer_01"));

	this->SetSprite(Resource->GetSprite(L"S_Hammer_00"));

	this->SetName("Hammer");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 30, 30));//이게 약간 이상함..
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 30, 30));//사이즈가 안 변함
}
void HammerActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void HammerActor::Update()
{
	Super::Update();

	this->Move();
	if (Input->GetKeyDown(KeyCode::LeftMouse))
	{
		this->SetSprite(Resource->GetSprite(L"S_Hammer_01"));
	}
	if (Input->GetKeyUp(KeyCode::LeftMouse))
	{
		this->SetSprite(Resource->GetSprite(L"S_Hammer_00"));
	}
}
void HammerActor::Release()
{
	Super::Release();
}

void HammerActor::Move()
{
	_hammerPos.x = Input->GetMousePos().x - 150;
	_hammerPos.y = Input->GetMousePos().y - 150;

	_body.pos = _hammerPos;
}