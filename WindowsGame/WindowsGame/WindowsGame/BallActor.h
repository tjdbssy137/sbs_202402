#pragma once
#include "Actor.h"
class BallActor : public Actor
{
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;

public:
	void Move();
	void SetPos(Vector2 position);
	void SetMoveDir(Vector2 moveDir) { _moveDir = moveDir; }
	Vector2 GetMoveDir() { return _moveDir; }

private:
	float _speed = 0.0f;
	Vector2 _moveDir;
};

