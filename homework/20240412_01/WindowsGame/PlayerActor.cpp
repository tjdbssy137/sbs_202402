#include "pch.h"
#include "PlayerActor.h"
#include "BoxCollider.h"

void PlayerActor::Init()
{
	Super::Init();

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 60, 60));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(100, 100, 60, 60));

	_speed = 400;
}
void PlayerActor::Render(HDC hdc)
{
	Super::Render(hdc);

	_body.Draw(hdc);
}
void PlayerActor::Update()
{
	Super::Update();
	/*
	if (Input->GetKeyDown(KeyCode::RightMouse) && _name == "플레이어1")
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
	if (Input->GetKey(KeyCode::A))
	{
		this->Move(Vector2::Left());
	}
	if (Input->GetKey(KeyCode::D))
	{
		this->Move(Vector2::Right());
	}
}
void PlayerActor::Release()
{
	Super::Release();
}

void PlayerActor::Move(Vector2 moveDir)
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
}

void PlayerActor::SetPos(Vector2 position)
{
	this->_body.pos = position;
}