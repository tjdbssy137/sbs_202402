#pragma once
#include "Scene.h"
class MoleActor;
class SpriteActor;
class MoleGameScene : public Scene
{
public:
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void ChangeGameState(MoleGameState state);
	MoleGameState GetGameState() { return _gameState; }

private:
	MoleGameState _gameState = MoleGameState::None;
	SpriteActor* _hammer = nullptr;
	vector<MoleActor*> _mole;
	float _regenTimer = 0;
};

