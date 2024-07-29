#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"
class Flipbook; 
class CircleCollider;
class BoatActor;
class BulletActorController;

enum class BehicleState
{
	Attack,
	Submarine,
	Idle,
	None
};

class BehicleActor : public FlipbookActor, public ITilemapActor
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
	void SetState(BehicleState state) { _state = state; }
	BehicleState GetState() { return _state; }

	void ChangeDirection(eDirection dir);

public:
	void SetBehicleData(BehicleData data) { _data = data; }
	BehicleData GetBehicleData() { return _data; }

public:
	void UpdateAttack();
	void UpdateIdle();

public:
	void LookAtTarget();
	void UseBullet();
	void SetActiveBehicle();

private:
	BehicleState _state = BehicleState::Idle;
	eDirection _dir = eDirection::DOWN;
	Flipbook* _idleFlipbook[8] = {};

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};

private:
	CircleCollider* _collider = nullptr;
	float _time = 1.0f;
	vector<BoatActor*> _boats;
	BoatActor* _targetBoat = nullptr;
	BulletActorController* _bulletActorController = nullptr;

	BehicleData _data; // data를 처음부터 갖고 시작.
};