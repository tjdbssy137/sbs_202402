#pragma once
#include "Actor.h"
class Sprite;
class SpriteActor : public Actor
{
protected:
	Sprite* _sprite = nullptr;

public:
	void SetSprite(Sprite* sprite) { _sprite = sprite; }
	Sprite* GetSprite() { return _sprite; }

public:
	using Super = Actor;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	SpriteActor() {}
	virtual ~SpriteActor() {}
};

