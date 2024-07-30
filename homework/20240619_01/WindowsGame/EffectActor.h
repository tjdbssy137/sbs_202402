#pragma once
#include "FlipbookActor.h"

enum class EffectState
{
	Start,
	End,
	None
};
class EffectActor : public FlipbookActor
{
private:
	DECLARE_CHILD(EffectActor, FlipbookActor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void SetEffect(wstring effect) { _effect = effect; }
	wstring GetEffect() { return _effect; }
	void OnEffect(float time = 5);
	void OffEffect();
private:
	EffectState _state = EffectState::None;
	wstring _effect = L"FB_Bomb";
	float _time = 0;
};

