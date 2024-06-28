#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"
class BoxCollider;
class Flipbook;

enum class BoatState
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

public: // ��ӹ��� �������̽��� �Լ��� ������ ������ ������ ��.
	virtual void SetCellPos(Vector2Int cellPos, bool teleport = false) override;
	virtual Vector2Int GetCellPos() override;

public:
	void SetState(BoatState state);
	BoatState GetState() { return _state; }

	void SetVelocity(Vector2 velocity) { _velocity = velocity; }
	Vector2 GetVelocity() { return _velocity; }

	void SetDirNewPos(Vector2 dirNewPos) { _dirNewPos = dirNewPos; }
	Vector2 GetDirNewPos() { return _dirNewPos; }

	void ChangeDirection(eDirection dir);

	void SetDestPos(Vector2 destPos) { _destPos = destPos; }
	Vector2 GetDestPos() { return _destPos; }

public:
	bool HasRechedDest();
	bool CanMove();
public:
	void SetIsAttackInput(bool isAttackInput) { _isAttackInput = isAttackInput; }
	bool GetIsAttackInput() { return _isAttackInput; }

public: // Astar ����
	void SetPath(vector<Vector2Int> path);


public:
	void UpdateMove();
	void UpdateIdle();

private:
	BoatState _state = BoatState::Move;
	eDirection _dir = eDirection::DOWN;
	Flipbook* _moveFlipbook[eDirection::END] = {};

	BoxCollider* collider = nullptr;
private:
	float _invokeTime = 0;
	Vector2 _velocity = {};
	Vector2 _dirNewPos = {};
	bool _isAttackInput = false;

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};
private:// Astar ����
	vector<Vector2Int> _path = {};
	int _pathIndex = 0;
};