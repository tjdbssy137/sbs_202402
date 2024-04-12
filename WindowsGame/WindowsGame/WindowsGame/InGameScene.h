#pragma once
#include "Scene.h"

class BrickActor;
class BallActor;
class PaddleActor;
class PlayerController;
class InGameState;

enum class GameState
{
	None,
	Wait,
	Play,
};

class InGameScene :
    public Scene
{
private:
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void ChangeGameState(GameState state);
	GameState GetGameState() { return _gameState; }

private:
	PaddleActor* _paddle = nullptr;
	BallActor* _ball = nullptr;
	PlayerController* _playerController = nullptr;
	GameState _gameState = GameState::None;
	//brick¿∫ vector2∑Œ
};

