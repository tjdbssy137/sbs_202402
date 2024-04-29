#pragma once
#include "SpriteActor.h"
class BadukActor :  public SpriteActor
{
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

