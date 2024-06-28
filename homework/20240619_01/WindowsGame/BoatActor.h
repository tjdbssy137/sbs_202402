#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"
class CircleCollider;
class Flipbook;

enum class BoatState
{
	Move,
	Idle
};

class BoatActor : public FlipbookActor, public ITilemapActor
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

	void ChangeDirection(eDirection dir);

	void SetDestPos(Vector2 destPos) { _destPos = destPos; }
	Vector2 GetDestPos() { return _destPos; }

public:
	bool HasRechedDest();
	bool CanMove();
public:
	void SetBoatSpeed(int boatSpeed) { _boatSpeed = boatSpeed; }
	int GetBoatSpeed() { return _boatSpeed; }

	void SetBoatType(wstring boatType) { _boatType = boatType; }
	wstring GetBoatType() { return _boatType; }

public: // Astar ����
	void SetPath(vector<Vector2Int> path);


public:
	void UpdateMove();
	void UpdateIdle();

private:
	BoatState _state = BoatState::Move;
	eDirection _dir = eDirection::DOWN;
	Flipbook* _moveFlipbook[eDirection::END] = {};

	CircleCollider* collider = nullptr;

private: // scene ���� ����
	int _boatSpeed = 100;
	wstring _boatType = L"FB_EnemyBoat1_";

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};
private:// Astar ����
	vector<Vector2Int> _path = {};
	int _pathIndex = 0;
};