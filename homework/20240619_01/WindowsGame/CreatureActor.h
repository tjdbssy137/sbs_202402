#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"
class BoxCollider;
class Flipbook;

enum eCreatureDirection
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

enum class CreatureState
{
	Move,
	Idle
};

class CreatureActor : public FlipbookActor, public ITilemapActor
{
public:
	using Super = FlipbookActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public: // 상속받은 인터페이스의 함수를 만들지 않으면 오류가 남.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) override;
	virtual Vector2Int GetCellPos() override;

public:
	void SetState(CreatureState state);
	CreatureState GetState() { return _state; }

	void SetVelocity(Vector2 velocity) { _velocity = velocity; }
	Vector2 GetVelocity() { return _velocity; }

	void SetDirNewPos(Vector2 dirNewPos) { _dirNewPos = dirNewPos; }
	Vector2 GetDirNewPos() { return _dirNewPos; }

	void ChangeDirection(eCreatureDirection dir);

	void SetDestPos(Vector2 destPos) { _destPos = destPos; }
	Vector2 GetDestPos() { return _destPos; }

public:
	bool HasRechedDest();
	bool CanMove();
public:
	void SetIsAttackInput(bool isAttackInput) { _isAttackInput = isAttackInput; }
	bool GetIsAttackInput() { return _isAttackInput; }

public: // Astar 관련
	void SetPath(vector<Vector2Int> path);


public:
	void UpdateMove();
	void UpdateIdle();

private:
	CreatureState _state = CreatureState::Move;
	eCreatureDirection _dir = eCreatureDirection::DOWN;
	Flipbook* _moveFlipbook[eCreatureDirection::END] = {};

	BoxCollider* collider = nullptr;
private:
	float _invokeTime = 0;
	Vector2 _velocity = {};
	Vector2 _dirNewPos = {};
	bool _isAttackInput = false;

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};
private:// Astar 관련
	vector<Vector2Int> _path = {};
	int _pathIndex = 0;
};