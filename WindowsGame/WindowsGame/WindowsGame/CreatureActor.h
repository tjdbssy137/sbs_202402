#pragma once
#include "FlipbookActor.h"
class Flipbook;

enum eCreatureDirection
{
	Down,
	Up,
	Left,
	Right,

	End
};

enum class CreatureState
{
	Attack,
	Move,
	Idle
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
	void SetState(CreatureState state);
	CreatureState GetState() { return _state; }

	void SetVelocity(Vector2 velocity) { _velocity = velocity; }
	Vector2 GetVelocity() { return _velocity; }

	void ChangeDirection(eCreatureDirection dir);
	void UpdateInput();
public:
	void SetIsAttackInput(bool isAttackInput) { _isAttackInput = isAttackInput; }
	void UpdateMove();
	void UpdateAttack();
	void UpdateIdle();
private:
	CreatureState _state = CreatureState::Idle;

	eCreatureDirection _dir = eCreatureDirection::Down;
	Flipbook* _idleFlipbook[eCreatureDirection::End] = {};
	Flipbook* _attackFlipbook[eCreatureDirection::End] = {};
	Flipbook* _moveFlipbook[eCreatureDirection::End] = {};
private:
	float _invokeTime = 0;
	Vector2 _velocity = {};
	bool _isAttackInput = false;
};