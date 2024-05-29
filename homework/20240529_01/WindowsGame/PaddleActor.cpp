#include "pch.h"
#include "PaddleActor.h"

#include "BoxCollider.h"

void PaddleActor::Init()
{
	Super::Init();

	Resource->LoadTexture(L"T_paddle", L"BrickGame/paddle.bmp");
	Resource->CreateSprite(L"S_paddle", Resource->GetTexture(L"T_paddle"));


	this->SetSprite(Resource->GetSprite(L"S_paddle"));

	this->SetName("Paddle");

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 108, 21));
	this->AddComponent(collider);
	this->SetBody(Shape::MakeCenterRect(WIN_SIZE_X / 2, WIN_SIZE_Y - 70, 108, 21));

	_speed = 500;
}

void PaddleActor::Render(HDC hdc)
{
	Super::Render(hdc);

	//_body.Draw(hdc);
}

void PaddleActor::Update()
{
	Super::Update();

}

void PaddleActor::Release()
{
	Super::Release();
}

void PaddleActor::Move(Vector2 moveDir)
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