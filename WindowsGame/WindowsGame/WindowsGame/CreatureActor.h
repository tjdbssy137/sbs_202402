#pragma once
#include "FlipbookActor.h"
class FlipbookActor;
class Flipbook;

enum class CreatureState
{
	Attack,
	Move,
	Idle,

	None
};

enum class CreatureDirectionState
{
	Down,
	Up,
	Left,
	Right,

	None
};

class CreatureActor : public FlipbookActor
{
public:
	using Super = FlipbookActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void DoIdle();
	void DoAttack();
	void DoMove();
	void SetDirState(CreatureDirectionState dirState) { _dirState = dirState; }
	CreatureState GetState() { return _state; }
	
public:
	void ChangeState(CreatureState state);
private:
	CreatureState _state = CreatureState::None;
	CreatureDirectionState _dirState = CreatureDirectionState::None;
};

