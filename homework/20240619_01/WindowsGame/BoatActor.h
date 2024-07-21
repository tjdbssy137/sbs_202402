#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"
class CircleCollider;
class Flipbook;
class Sprite;
class BulletActorController;

enum class BoatState
{
	Start,
	Move,
	Idle,
	Goal,
	Die,
	None
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
	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;

public:
	void SetState(BoatState state) { _state = state; }
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

	void SetBoatHp(float hp) { _hp = hp; }
	void SetBoatStaticHp(float hp) { _staticHp = hp; _nextHp = hp;  }

	CircleCollider* GetBoatCollider() { return collider; }

public: // Astar ����
	void SetPath(vector<Vector2Int> path);

public:
	void UpdateMove();
	void UpdateIdle();
	void SetActiveBoat();
public:
	void UpdateHpImage(float _tempHP);

	void FinishedBoatState();
	void DeathEffect();
private:
	BoatState _state = BoatState::Idle;
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

private:
	float _hp = 100.0f;
	float _staticHp = 100.0f;
	float _nextHp = 100.0f;
	Sprite* _hpBackground = nullptr;
	Sprite* _bpBar = nullptr;

private:
	Flipbook* _bomb = nullptr;
	bool _die = false;
	float _time = 0.6f;

private:
	BulletActorController* _bulletActorController = nullptr;
};