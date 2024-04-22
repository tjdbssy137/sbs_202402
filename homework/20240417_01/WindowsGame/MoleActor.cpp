#include "pch.h"
#include "MoleActor.h"
#include "BoxCollider.h"
#include "WhacAMole.h"

void MoleActor::Init()
{
	Super::Init();

	this->SetName("Mole");
	Resource->LoadTexture(L"T_Mole_00", L"Mole/mole_00.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_Mole_00", Resource->GetTexture(L"T_Mole_00"));
	
	Resource->LoadTexture(L"T_Mole_01", L"Mole/mole_01.bmp");//확장자명은 내가 쓰는 거 아님.
	Resource->CreateSprite(L"S_Mole_01", Resource->GetTexture(L"T_Mole_01"));

	this->SetSprite(Resource->GetSprite(L"S_Mole_00"));

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 20, 30));//이게 약간 이상함..
	this->SetBody(Shape::MakeCenterRect(0, 1000, 20, 30));
	this->AddComponent(collider);
	
	_isCollision = false;
}
void MoleActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void MoleActor::Update()
{
	Super::Update();
}
void MoleActor::Release()
{
	Super::Release();
}

void MoleActor::OnTriggerEnter(Collider* collider, Collider* other)
{
	Super::OnTriggerEnter(collider, other);
	if (other->GetOwner()->GetName() == "Hammer" && Input->GetKey(KeyCode::LeftMouse))
	{
		_isCollision = true;
	}
}

void MoleActor::OnTriggerExit(Collider* collider, Collider* other)
{
	Super::OnTriggerExit(collider, other);
	if (other->GetOwner()->GetName() == "Hammer")
	{
		_isCollision = false;
	}
}

void MoleActor::HitHammer()
{
	if (_isCollision == true)
	{
		this->SetSprite(Resource->GetSprite(L"S_Mole_01"));
	}
	_time += Time->GetDeltaTime();
	if (1 < _time)
	{
		this->SetBody(Shape::MakeCenterRect(0, 1000, 20, 30)); //->WhacAMole에서 위치 다시 잘 잡기 알아서
		this->SetSprite(Resource->GetSprite(L"S_Mole_00"));
		_time = 0;
	}
}

void MoleActor::MoleAppears()
{
	this->SetBody(_molePos);
	if (_isCollision == true)
	{
		this->SetSprite(Resource->GetSprite(L"S_Mole_01"));

		if (1 < _time)
		{
			this->SetBody(Shape::MakeCenterRect(0, 1000, 20, 30)); //->WhacAMole에서 위치 다시 잘 잡기 알아서
			this->SetSprite(Resource->GetSprite(L"S_Mole_00"));
			_time = 0;
			return;
		}
	}
	else
	{
		if (1.5f < _time)
		{
			this->SetBody(Shape::MakeCenterRect(0, 1000, 20, 30));
			_time = 0;
		}
	}
}