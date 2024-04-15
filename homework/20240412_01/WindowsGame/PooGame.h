#pragma once
#include "Scene.h"

class PlayerActor;
class PooActor;
class InGameState;
class PooGameController;

#define IS_ACTIVE 20
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
	bool _isActive[IS_ACTIVE];

	PooGameController* _pooGameController = nullptr;
	GameState _gameState = GameState::None;

	float _tempTime = 0;
	float _throwTime = 0;
	int _level = 1;
};

