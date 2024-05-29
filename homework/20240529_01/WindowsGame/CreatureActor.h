#pragma once
#include "FlipbookActor.h"
class Flipbook;

enum eCreatureDirection
{
	RIGHT,
	LEFT,
	UP,
	DOWN,
	END
};

enum class CreatureState
{
	Idle,
	Move,
	Attack
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
	void SetVelocity(Vector2 velocity) { _velocity = velocity; }
	Vector2 GetVelocity() { return _velocity; }

	void SetDirNewPos(Vector2 dirNewPos) { _dirNewPos = dirNewPos; }
	Vector2 GetDirNewPos() { return _dirNewPos; }


public:
	void SetState(CreatureState state);
	void ChangeDirection(eCreatureDirection dir);

public:
	void UpdateIdle();
	void UpdateMove();
	void UpdateAttack();

public:
	void SetIsAttackInput(bool isAttackInput) { _isAttackInput = isAttackInput; }
protected:
	bool _isAttackInput = false;

	Vector2 _velocity = {};

	Vector2 _dirNewPos = {};

	CreatureState _state = CreatureState::Idle;
	eCreatureDirection _dir = eCreatureDirection::DOWN;
	Flipbook* _idleFlipbook[eCreatureDirection::END] = {};
	Flipbook* _moveFlipbook[eCreatureDirection::END] = {};
	Flipbook* _attackFlipbook[eCreatureDirection::END] = {};

};

