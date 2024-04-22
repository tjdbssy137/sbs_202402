#pragma once
#include "SpriteActor.h"
class BackgroundActor :  public SpriteActor
{
private:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

};

