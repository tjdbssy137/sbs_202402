#include "pch.h"
#include "EffectActor.h"

void EffectActor::Init()
{
	Super::Init();
}
void EffectActor::Update()
{
	Super::Update();
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
	this->SetFlipbook(Resource->GetFlipbook(_effect));
	this->_index = 0;
	_time = time;
	_state = EffectState::Start;
}
void EffectActor::OffEffect()
{
	this->SetPos({10000, 10000});
	_state = EffectState::None;
}