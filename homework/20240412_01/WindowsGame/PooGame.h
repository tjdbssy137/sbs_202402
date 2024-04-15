#pragma once
#include "Scene.h"

class PlayerActor;
class PooActor;
class InGameState;
class PooGameController;

#define isActive 18
class PooGame : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

	void ChangeGameState(GameState state);
	GameState GetGameState() { return _gameState; }

private:
	PlayerActor* player = nullptr;
	vector<PooActor*> _poo;
	float _time = 0;
	float _survivalTime = 0;
	bool _isActive[isActive];

	PooGameController* pooGameController = nullptr;
	GameState _gameState = GameState::None;

};

