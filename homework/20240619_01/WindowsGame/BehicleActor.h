#pragma once
#include "FlipbookActor.h"
class Flipbook; 

enum eBehicleDirection
{
	DOWN,
	LEFT,
	RIGHT,
	UP,
	DOWN_LEFT,
	DOWN_RIGHT,
	UP_LEFT,
	UP_RIGHT,
	END
};

enum class BehicleState
{
	Attack,
	Idle
};

class BehicleActor : public FlipbookActor
{
public:
	using Super = FlipbookActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void SetState(BehicleState state);
	BehicleState GetState() { return _state; }

	void ChangeDirection(eBehicleDirection dir);

public:
	void SetBoatSpeed(int behicleSpeed) { _behicleShotSpeed = behicleSpeed; }
	int GetBoatSpeed() { return _behicleShotSpeed; }

	void SetBehicleType(wstring behicleType) { _behicleType = behicleType; }
	wstring GetBehicleType() { return _behicleType; }

public:
	void UpdateAttack();
	void UpdateIdle();

public:
	void LookAtTarget();

private:
	BehicleState _state = BehicleState::Idle;
	eBehicleDirection _dir = eBehicleDirection::DOWN;
	Flipbook* _idleFlipbook[eBehicleDirection::END] = {};

private: // scene 에서 정리
	int _behicleShotSpeed = 200;
	wstring _behicleType = L"FB_EnemyBoat1_";

private:
	Vector2 _targetPos = {};
	Vector2Int _cellPos = {};
};