#pragma once
#include "Scene.h"
class Homework20 : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	//keyboard
	CenterRect _player;
	Vector2 _playerDir;

	CenterRect _ball;
	Vector2 _ballDir = {0, 0};
	Vector2 _Vector2Zero = { 0, 0 };

	//block
	CenterRect _block = {};
	CenterRect _blocks[40];
	bool _collisionCheck[40];

	//wall
	CenterRect _wallLeft;
	CenterRect _wallRight;

	//mouse
	Vector2 _targetPos = { -1, -1 };
	bool _mouseTurn = true;

};

