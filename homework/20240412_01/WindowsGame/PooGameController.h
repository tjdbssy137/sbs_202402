#pragma once
class PooActor;
class PlayerActor;

class PooGameController
{
public:
	void Init(PlayerActor* paddle);
	void Update();

	void SetCanPlayerController(bool canPlayerControl) { _canPlayerControl = canPlayerControl; }
	bool GetCanPlayerControl() { return _canPlayerControl; }

private:
	PlayerActor* _player = nullptr;
	bool _canPlayerControl = true;
};

