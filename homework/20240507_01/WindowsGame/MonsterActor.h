#pragma once
#include "FlipbookActor.h"
class Flipbook;
class BoxCollider;

enum eMonsterDirection
{
	MonsterDown,
	MonsterUp,
	MonsterLeft,
	MonsterRight,

	PK_END
};
enum class MonsterState
{
	Die,
	GetHit,
	Idle,

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
	void ChangeDirection(eMonsterDirection dirState);
	void DoDie();
	void DoIdle();
	void DoGetHit();
	MonsterState GetState() { return _state; }

	void SetMonsterHp() { _monsterHp--; }
	int GetMonsterHp() { return _monsterHp; }
	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;
public:
	void SetState(MonsterState state);

private:
	MonsterState _state = MonsterState::Idle;
	eMonsterDirection _dirState = eMonsterDirection::MonsterDown;
	Flipbook* _idleFlipbook[eMonsterDirection::PK_END] = {};

private:
	float _invokeTime = 0;
	int _monsterHp = 3;
	bool _isDie = false;

private:
	BoxCollider* collider = nullptr;
};

