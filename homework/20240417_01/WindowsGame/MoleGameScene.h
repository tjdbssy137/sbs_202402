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

public:
	void MovementMouse();

private:
	MoleGameState _gameState = MoleGameState::None;
	SpriteActor* _hammer = nullptr;
	vector<MoleActor*> _mole;
	int _posX[8] = {220, 220, 224, 428, 428, 620, 620, 622 };
	int _posY[8] = { 86, 237, 405, 160, 313, 86, 237, 405 };
	
	float _regenTimer = 0;
	float _playTime = 0;
	int _point = 0;
	
	bool _isHit = false;
	
};

