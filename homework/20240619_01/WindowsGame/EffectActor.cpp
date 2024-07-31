#include "pch.h"
#include "EffectActor.h"
#include "Flipbook.h"

void EffectActor::Init()
{
	Super::Init();
	this->SetPos({10000, 10000});
	this->SetFlipbook(Resource->GetFlipbook(_effect));
}
void EffectActor::Update()
{
	Super::Update();

	const FlipbookInfo& info = _flipbook->GetInfo();
	{

	}

	switch (_state)
	{
	case EffectState::Start:
	{
		_time -= Time->GetDeltaTime();
		if (_time <= 0)
		{
			_state = EffectState::End;
		}
	}
		break;
	case EffectState::End:
	{
		OffEffect();
	}
		break;
	default:
		break;
	}
}
void EffectActor::Render(HDC hdc)
{
	Super::Render(hdc);
}
void EffectActor::Release()
{
	Super::Release();
}
void EffectActor::OnEffect(float time)
{
	this->_index = 0;
	_time = time;
	_state = EffectState::Start;
}
void EffectActor::OffEffect()
{
	this->SetPos({10000, 10000});
	_state = EffectState::None;
}