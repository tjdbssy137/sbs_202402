#pragma once
class PooActor;
class PlayerActor;

class PooGameController
{
public:
	void Init(PlayerActor* paddle, vector<PooActor*> poo);
	void Update();

	void SetCanPlayerController(bool canPlayerControl) { _canPlayerControl = canPlayerControl; }
	bool GetCanPlayerControl() { return _canPlayerControl; }

private:
	PlayerActor* _player = nullptr;
	vector<PooActor*> _poo;
	bool _canPlayerControl = true;
};

