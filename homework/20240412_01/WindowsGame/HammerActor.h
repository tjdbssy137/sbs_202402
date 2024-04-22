#pragma once
#include "Actor.h"
class HammerActor : public Actor
{
private:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void SetUseHammer(bool useHammer) { _useHammer = useHammer; }

public:
	void Move();
private:
	Vector2 _hammerPos = {};
	bool _useHammer;
};
