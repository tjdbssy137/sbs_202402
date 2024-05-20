#pragma once
#include "FlipbookActor.h"
class BoxCollider;
class Flipbook;

enum eCreatureDirection
{
	PK_DOWN,
	PK_UP,
	PK_LEFT,
	PK_RIGHT,

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
	bool GetIsAttackInput() { return _isAttackInput; }

	void UpdateMove();
	void UpdateAttack();
	void UpdateIdle();


private:
	CreatureState _state = CreatureState::Idle;

	eCreatureDirection _dir = eCreatureDirection::PK_DOWN;
	Flipbook* _idleFlipbook[eCreatureDirection::End] = {};
	Flipbook* _attackFlipbook[eCreatureDirection::End] = {};
	Flipbook* _moveFlipbook[eCreatureDirection::End] = {};
	CenterRect _attackCollisionPos[eCreatureDirection::End] = {};

	BoxCollider* collider = nullptr;
private:
	float _invokeTime = 0;
	Vector2 _velocity = {};
	bool _isAttackInput = false;
};