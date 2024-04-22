#include "pch.h"
#include "HammerActor.h"
#include "BoxCollider.h"

void HammerActor::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_Hammer_00", L"Mole/hammer_00.bmp");//Ȯ���ڸ��� ���� ���� �� �ƴ�.
	Resource->CreateSprite(L"S_Hammer_00", Resource->GetTexture(L"T_Hammer_00"));

	Resource->LoadTexture(L"T_Hammer_01", L"Mole/hammer_01.bmp");//Ȯ���ڸ��� ���� ���� �� �ƴ�.
	Resource->CreateSprite(L"S_Hammer_01", Resource->GetTexture(L"T_Hammer_01"));

	this->SetSprite(Resource->GetSprite(L"S_Hammer_00"));

	this->SetName("Hammer");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 30, 30));//�̰� �ణ �̻���..
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y / 2, 30, 30));//����� �� ����
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