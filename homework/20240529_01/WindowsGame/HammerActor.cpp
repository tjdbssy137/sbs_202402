#include "pch.h"
#include "HammerActor.h"


void HammerActor::Init()
{
	Super::Init();
	this->SetName("Hammer");
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
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
	if (_state == state) return;

	_state = state;

	switch (_state)
	{
	case HammerActorState::Hit:
		this->DoHit();
		break;
	case HammerActorState::Idle:
		this->DoIdle();
		break;
	case HammerActorState::None:
		break;
	default:
		break;
	}

}

void HammerActor::DoHit()
{
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Hit"));

	// ÀÌÆåÆ® »ý¼º! 
}

void HammerActor::DoIdle()
{
	this->SetSprite(Resource->GetSprite(L"S_Hammer_Idle"));
}