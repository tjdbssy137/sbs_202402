#pragma once

enum class GameState
{
	None,
	Wait,
	Play
};

class InGameState
{
public:
	void SetGameState(GameState state) { _state = state; }
	GameState GetGameState() { return _state; }

private:
	GameState _state = GameState::None;
};

