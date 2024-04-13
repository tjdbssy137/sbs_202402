#pragma once
#include "Actor.h"

#define COUNT 48
class BrickActor : public Actor
{
public:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void SetBool(bool isDestroy) { *_isDestroy = isDestroy; }

private:
	CenterRect _bricks[COUNT];
	bool _isDestroy[COUNT];
};

