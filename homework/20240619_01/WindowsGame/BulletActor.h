#pragma once
#include "SpriteActor.h"
class BoatActor;
class BulletActorController;
enum class BulletState
{
	Move,
	Done
};

class BulletActor :  public SpriteActor
{
private:
	DECLARE_CHILD(BulletActor, SpriteActor);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void SetBulletDamage(float damage) { _damage = damage; }
	float GetBulletDamage() { return _damage; }

	void SetBulletSpeed(float speed) { _speed = speed; }
	float GetBulletSpeed() { return _speed; }

	void SetBulletState(BulletState state) { _state = state; }
public:
	void SetATarget(BoatActor* targetBoat);
	void Update_Move();

private:
	float _damage = 0;
	float _speed = 0;
	Vector2 _moveDir;
	BoatActor* _targetBoat = nullptr;
	BulletState _state = BulletState::Done;
	BulletActorController* _bulletActorController = nullptr;
};

