#pragma once
#include "Actor.h"
class PooActor :
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
	void Throw(float pPosX, float pPosY);
	void Move();
	//Vector2 GetPooPosition(){return this->_body.pos;};

private:
	Vector2 _targetPos = {};
	Vector2 _moveDir = {};
};

