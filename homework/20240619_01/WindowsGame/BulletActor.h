#pragma once
#include "SpriteActor.h"
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
public:
	void ShootingBullet(Actor* targetBoat);
	void Update_Move();

private:
	float _damage = 0;
	float _speed = 0;
	Vector2 _moveDir;
	Actor* _targetBoat = nullptr;
};

