#pragma once
#include "Actor.h"
class PlayerActor : public Actor
{
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;
	//bool GetIsGameOver() { return _isGameOver; }
	//void SetInGameOver(bool isGameOver) { _isGameOver = isGameOver; }

public:
	void Move(Vector2 moveDir);
	void SetPos(Vector2 position);

private:
	Vector2 _targetPos = {};
	Vector2 _moveDir = {};
	float _speed = 0.0f;

	//bool _isGameOver = false;
};

