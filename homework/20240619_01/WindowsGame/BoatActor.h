#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"
class CircleCollider;
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

public: // 상속받은 인터페이스의 함수를 만들지 않으면 오류가 남.
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
	float GetBoatHp() { return _hp;  }

	CircleCollider* GetBoatCollider() { return _collider; }

public:
	void SetBoatData(BoatData data) { _data = data; }
	BoatData GetBoatData() { return _data; }

public: // Astar 관련
	void SetPath(vector<Vector2Int> path);

public:
	void UpdateMove();
	void UpdateIdle();
	void SetActiveBoat();

public:
	void UpdateHpImage(float _tempHP);

private:
	BoatState _state = BoatState::Idle;
	eDirection _dir = eDirection::DOWN;
	Flipbook* _moveFlipbook[eDirection::END] = {};

	CircleCollider* _collider = nullptr;

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};
private:// Astar 관련
	vector<Vector2Int> _path = {};
	int _pathIndex = 0;

private:
	float _hp = 100.0f;
	float _staticHp = 100.0f;
	float _nextHp = 100.0f;
	Sprite* _hpBackground = nullptr;
	Sprite* _bpBar = nullptr;

private:
	BulletActorController* _bulletActorController = nullptr;
	BoatData _data;
};