#pragma once
#include "SpriteActor.h"

#define COUNT 48
class BrickActor : public SpriteActor
{
public:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
};

