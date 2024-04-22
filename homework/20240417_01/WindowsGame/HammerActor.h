#pragma once
#include "SpriteActor.h"
class HammerActor :
    public SpriteActor
{
private:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void Move();
private:
	Vector2 _hammerPos = {};
};

