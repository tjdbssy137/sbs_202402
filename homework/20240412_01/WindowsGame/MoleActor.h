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
	virtual void OnTriggerExit(Collider* collider, Collider* other) override;

public:
	void MoleGetsSmaller(RECT rect);
	void MoleGetsBigger(RECT rect);
	bool GetIsCollision() { return _fight; }
private:
	bool _isTrigger = true;
	bool _isCollision;

	bool _fight = false;

};

