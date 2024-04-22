#pragma once
#include "Scene.h"

class MoleActor;
class HammerActor;
class BackgroundActor;

class WhacAMole : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void MoleAppears();
	float GetTime() { return _time; };
	void SetTime(float time) { _time = time; };
private:

	vector<MoleActor*> _mole;
	HammerActor* _hammer = nullptr;
	BackgroundActor* _background = nullptr;

	vector<CenterRect> _savedPos;

	float _time = 0;

};

