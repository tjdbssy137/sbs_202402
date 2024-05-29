#pragma once
#include "FlipbookActor.h"
class BoxCollider;
class Flipbook;

enum eCreatureDirection
{
	DOWN,
	UP,
	LEFT,
	RIGHT,

	END
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

	void SetDirNewPos(Vector2 dirNewPos) { _dirNewPos = dirNewPos; }
	Vector2 GetDirNewPos() { return _dirNewPos; }

	void ChangeDirection(eCreatureDirection dir);

public:
	void SetIsAttackInput(bool isAttackInput) { _isAttackInput = isAttackInput; }
	bool GetIsAttackInput() { return _isAttackInput; }

	void UpdateMove();
	void UpdateAttack();
	void UpdateIdle();


private:
	CreatureState _state = CreatureState::Idle;
	eCreatureDirection _dir = eCreatureDirection::DOWN;
	Flipbook* _idleFlipbook[eCreatureDirection::END] = {};
	Flipbook* _moveFlipbook[eCreatureDirection::END] = {};
	Flipbook* _attackFlipbook[eCreatureDirection::END] = {};

	CenterRect _attackCollisionPos[eCreatureDirection::END] = {};

	BoxCollider* collider = nullptr;
private:
	float _invokeTime = 0;
	Vector2 _velocity = {};
	Vector2 _dirNewPos = {};
	bool _isAttackInput = false;
};