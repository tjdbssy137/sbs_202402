#include "pch.h"
#include "HammerActor.h"
#include "BoxCollider.h"

void HammerActor::Init()
{
	Super::Init();
	this->SetName("Hammer");
	this->SetBody(Shape::MakeCenterRect(0, 0, 51, 51));
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));

	BoxCollider* collider = new BoxCollider();
	collider->SetCollision(Shape::MakeCenterRect(0, 0, 50, 50));
	this->AddComponent(collider);
}
void HammerActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void HammerActor::Update()
{
	Super::Update();
}
void HammerActor::Release()
{
	Super::Release();
}

void HammerActor::ChangeState(HammerActorState state)
{
	//FSM 유한상태머신
	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case HammerActorState::Idle:
		this->DoIdle();
		break;
	case HammerActorState::Hit:
		this->DoHit();
		break;
	case HammerActorState::None:
		break;
	default:
		break;
	}
}

void HammerActor::DoIdle()
{
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
}

void HammerActor::DoHit()
{
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Hit"));
	// 만약 추가할 게 있다면 "이펙트 생성"
}