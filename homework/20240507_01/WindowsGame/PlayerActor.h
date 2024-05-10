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

private:
	Vector2 _targetPos = {};
	Vector2 _moveDir = {};
};

