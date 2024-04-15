#pragma once
#include "Actor.h"
class MoleActor : public Actor
{
private:
	using Super = Actor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;

public:
	void MoleGetsSmaller(RECT rect);
	void MoleGetsBigger(RECT rect);

private:
	bool _isTrigger = true;
};

