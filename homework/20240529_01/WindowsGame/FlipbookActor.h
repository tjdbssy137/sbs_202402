#pragma once
#include "Actor.h"
class FlipbookActor : public Actor
{
protected:
	Flipbook* _flipbook = nullptr;
	int _index = 0;
	float _sumTime = 0.0f;

public:
	void SetFlipbook(Flipbook* flipbook);
	void Reset();

public:
	using Super = Actor;

public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	FlipbookActor() {}
	virtual ~FlipbookActor() {}
};

