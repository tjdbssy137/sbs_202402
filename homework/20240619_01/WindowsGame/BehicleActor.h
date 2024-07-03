#pragma once
#include "FlipbookActor.h"
#include "ITilemapActor.h"
class Flipbook; 
class CircleCollider;
class BoatActor;
enum class BehicleState
{
	Attack,
	Idle
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
	//virtual void OnTriggerEnter(Collider* collider, Collider* other) override;

public:
	void SetState(BehicleState state);
	BehicleState GetState() { return _state; }

	void ChangeDirection(eDirection dir);

public:
	void SetBulletSpeed(float behicleSpeed) { _behicleBulletSpeed = behicleSpeed; }
	float GetBulletSpeed() { return _behicleBulletSpeed; }

	void SetBulletDamage(float behicleBulletDamage) { _behicleBulletDamage = behicleBulletDamage; }
	float GetBulletDamage() { return _behicleBulletDamage; }

	void SetBehicleType(wstring behicleType) { _behicleType = behicleType; }
	wstring GetBehicleType() { return _behicleType; }

	void SetBehicleDamage(float deal) { _damage = deal; }
	float GetBehicleDamage() { return _damage; }

public:
	void UpdateAttack();
	void UpdateIdle();

public:
	void LookAtTarget();

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
	Vector2 _targetPos = {};

private:
	CircleCollider* collider = nullptr;
	float _time = 1.0f;
	float _damage = 10;
	BoatActor* _targetBoat = nullptr;
};