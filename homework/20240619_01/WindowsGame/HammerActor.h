#pragma once
#include "SpriteActor.h"
enum class HammerActorState
{
	Idle,
	Hit,

	None
};
class HammerActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	void DoIdle();
	void DoHit();
	HammerActorState GetState() { return _state; }
public:
	void ChangeState(HammerActorState state);
private:
	HammerActorState _state = HammerActorState::None;
};
