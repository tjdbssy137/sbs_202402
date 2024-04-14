#include "pch.h"
#include "PooActor.h"
#include "BoxCollider.h"

void PooActor::Init()
{
	Super::Init();
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 50, 50));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(100, 100, 50, 50));
}
void PooActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void PooActor::Update()
{
	Super::Update();
	/*
	if (_name == "Poo")
	{
		POINT pt = Input->GetMousePos();
		_targetPos = Vector2(pt.x, pt.y);
		_moveDir = (_targetPos - _body.pos).Normalize();
	}

	if (10 < (_targetPos - _body.pos).Length())
	{
		_body.pos += _moveDir * (Time->GetDeltaTime() * 100);
	}
	*/
}
void PooActor::Release()
{
	Super::Release();
}