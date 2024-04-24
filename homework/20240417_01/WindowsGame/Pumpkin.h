#pragma once
#include "SpriteActor.h"
class Pumpkin : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void Throw(float pPosX);
	void Move();
	void SetMoveDir(Vector2 moveDir) { _moveDir = moveDir; }
	//Vector2 GetPooPosition(){return this->_body.pos;};

private:
	Vector2 _targetPos = {};
	Vector2 _moveDir = {};
};
