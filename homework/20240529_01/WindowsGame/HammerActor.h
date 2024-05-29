#pragma once
#include "SpriteActor.h"

enum class HammerActorState
{
	Hit,
	Idle,
	None,
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

	void ChangeState(HammerActorState state);
	HammerActorState GetState() { return _state; }

private:
	void DoHit();
	void DoIdle();

private:
	HammerActorState _state;
};

