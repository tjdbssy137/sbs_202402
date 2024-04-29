#include "pch.h"
#include "NumberRectActor.h"
#include "BoxCollider.h"

void NumberRectActor::Init()
{
	Super::Init();
	
	this->SetName("NumberRect");
	this->SetSprite(Resource->GetSprite(L"S_Number_2"));

	/*
	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 300, 300));
	this->AddComponent(collider);
	*/
	_speed = 100;
}
void NumberRectActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void NumberRectActor::Update()
{
	Super::Update();
}
void NumberRectActor::Release()
{
	Super::Release();
}

void NumberRectActor::SlideActor()
{
	this->SetPos(GetPos() + _direcion * _speed * Time->GetDeltaTime());
}

void NumberRectActor::ChangeImage(int sum)
{
	switch (sum)
	{
	case 4:
		this->SetSprite(Resource->GetSprite(L"S_Number_4"));
		break;
	case 8:
		this->SetSprite(Resource->GetSprite(L"S_Number_8"));
		break;
	case 16:
		this->SetSprite(Resource->GetSprite(L"S_Number_16"));
		break;
	case 32:
		this->SetSprite(Resource->GetSprite(L"S_Number_32"));
		break;
	case 64:
		this->SetSprite(Resource->GetSprite(L"S_Number_64"));
		break;
	case 128:
		this->SetSprite(Resource->GetSprite(L"S_Number_128"));
		break;
	case 256:
		this->SetSprite(Resource->GetSprite(L"S_Number_256"));
		break;
	case 512:
		this->SetSprite(Resource->GetSprite(L"S_Number_512"));
		break;
	case 1024:
		this->SetSprite(Resource->GetSprite(L"S_Number_1024"));
		break;
	case 2048:
		this->SetSprite(Resource->GetSprite(L"S_Number_2048"));
		break;
	default:
		this->SetSprite(nullptr);
		break;
	}
}

void NumberRectActor::ChangeDirectionState(MoveDirectionState directionState)
{
	switch (directionState)
	{
	case MoveDirectionState::Down:
		_direcion = Vector2::Down();
		break;

	case MoveDirectionState::Up:
		_direcion = Vector2::Up();
		break;

	case MoveDirectionState::Left:
		_direcion = Vector2::Left();
		break;

	case MoveDirectionState::Right:
		_direcion = Vector2::Right();
		break;
	case MoveDirectionState::None:
		_direcion = Vector2::Zero();
		break;
	}
}