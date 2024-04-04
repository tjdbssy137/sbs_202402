#pragma once
#include "Scene.h"
class homeworkScene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	CenterRect _ball;
	Vector2 _ballDir;
	Vector2 _targetPos = { -1, -1 };
	Vector2 _prevPos = { -1, -1 };

	CenterRect _roofRect;
	CenterRect _floorRect;

	CenterRect _leftPlayer;
	Vector2 _leftPlayerDir;
	CenterRect _rightPlayer;
	Vector2 _rightPlayerDir;

	int _moveRange1 = 0;
	int _moveRange2 = 0;

	int _leftPoint = 0;
	int _rightPoint = 0;
	bool _whoseTurn = true; // true == leftPlayer, false == rightPlayer
	bool _mouseTurn = true;
};

