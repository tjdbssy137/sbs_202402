#pragma once
#include "Scene.h"
class SpriteActor;
class MoleActor;
class HammerActor;
class PlayerHammerController;
class MoleGameScene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	void ChangeGameState(MoleGameState state);
	MoleGameState GetGameState() { return _gameState; }

	void PlusScore() { _score++; }

private:
	MoleGameState _gameState = MoleGameState::None;
	HammerActor* _hammer = nullptr;
	PlayerHammerController* _playerHammerController;

	float _regenTimer = 0.5f;
	vector<MoleActor*> _moles;
	int _score = 0;
};

