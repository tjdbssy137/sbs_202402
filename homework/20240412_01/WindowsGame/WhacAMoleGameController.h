#pragma once
class HammerActor;

class WhacAMoleGameController
{
public:
	void Init(HammerActor* hammer);
	void Update();

	void SetCanHammerController(bool canHammerControl) { _canHammerControl = canHammerControl; };
	bool GetCanHammerController() { return _canHammerControl; }
private:
	HammerActor* _hammer = nullptr;
	bool _canHammerControl = true;
};

