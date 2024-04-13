#pragma once
#include "Actor.h"
class PaddleActor :
    public Actor
{
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void Move(Vector2 moveDir);
	void SetPos(Vector2 position);

private:
	float _speed = 0.0f;
};

