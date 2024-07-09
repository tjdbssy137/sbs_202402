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
	void SetState(BehicleState state);
	BehicleState GetState() { return _state; }

	void ChangeDirection(eDirection dir);
public:
	void SetBehicleType(wstring behicleType) { _behicleType = behicleType; }
	wstring GetBehicleType() { return _behicleType; }

	void SetBulletDamage(float deal) { _behicleBulletDamage = deal; }
	float GetBulletDamage() { return _behicleBulletDamage; }
	
	void SetBulletSpeed(float speed) { _behicleBulletSpeed = speed; }
	float GetBulletSpeed() { return _behicleBulletSpeed; }

	void SetAttackTime(float time) { _attackTime = time; }
	
	CircleCollider* GetBehicleCollider() { return collider; }

	void SetColliderSize(int size) { _colliderSize = size; }

public:
	void UpdateAttack();
	void UpdateIdle();

public:
	void LookAtTarget();
	void LoadBullet();
	void SetActiveBehicle();
private:
	BehicleState _state = BehicleState::Idle;
	eDirection _dir = eDirection::DOWN;
	Flipbook* _idleFlipbook[8] = {};

private: // scene 에서 정리
	float _behicleBulletSpeed = 400;
	float _behicleBulletDamage = 10;
	wstring _behicleType = L"FB_Tank1_";

private:
	Vector2 _destPos = {};
	Vector2Int _cellPos = {};

private:
	CircleCollider* collider = nullptr;
	int _colliderSize = 150;
	float _attackTime = 1.0f;
	float _time = 1.0f;
	BoatActor* _targetBoat = nullptr;
	BulletActorController* _bulletActorController = nullptr;
};