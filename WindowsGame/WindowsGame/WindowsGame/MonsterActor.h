#pragma once
#include "FlipbookActor.h"
class Flipbook;

enum class MonsterState
{
	Die,
	GetHit,
	Idle,

	None
};

enum class MonsterDirectionState
{
	Down,
	Up,
	Left,
	Right,

	None
};

class MonsterActor :  public FlipbookActor
{
public:
	using Super = FlipbookActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void LookAtPlayer(Vector2 playerPos);
	void DoDie();
	void DoIdle();
	void DoGetHit();
	MonsterState GetState() { return _state; }
	void SetMonsterHp() { _monsterHp--; }
	int GetMonsterHp() { return _monsterHp; }

public:
	void ChangeState(MonsterState state);

private:
	MonsterState _state = MonsterState::None;
	MonsterDirectionState _dirState = MonsterDirectionState::None;

private:
	float _invokeTime;
	int _monsterHp = 3;
	bool _isDie = false;
};

