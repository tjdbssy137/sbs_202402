#pragma once
#include "SpriteActor.h"
class MoleActor :  public SpriteActor
{
private:
	using Super = SpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	virtual void OnTriggerEnter(Collider* collider, Collider* other) override;
	virtual void OnTriggerExit(Collider* collider, Collider* other) override;

	void HitHammer();
	void GetMolePos(CenterRect molePos) { _molePos = molePos; };
	void MoleAppears();

private:
	bool _isCollision = false;
	float _time = 0;
	bool _isCalled = false;
	CenterRect _molePos;
};