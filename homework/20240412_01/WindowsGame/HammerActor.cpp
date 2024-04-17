#include "pch.h"
#include "HammerActor.h"
#include "BoxCollider.h"

void HammerActor::Init()
{
	Super::Init();
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 15, 15));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y/2, 30, 30));
	_useHammer = false;
}
void HammerActor::Render(HDC hdc)
{
	Super::Render(hdc);
	if (_useHammer == true)
	{
		_body.Draw(hdc);
	}
}
void HammerActor::Update()
{
	Super::Update();

	this->Move();
}
void HammerActor::Release()
{
	Super::Release();
}

void HammerActor::Move()
{
	_hammerPos.x = Input->GetMousePos().x;
	_hammerPos.y = Input->GetMousePos().y;

	_body.pos = _hammerPos;
}