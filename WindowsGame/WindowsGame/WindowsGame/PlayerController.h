#pragma once
class PaddleActor;
class BallActor;
class PlayerController
{
public:
	void Init(PaddleActor* paddle, BallActor* ball);
	void Update();

	void SetCanBallController(bool cannBallControl) { _cannBallControl = cannBallControl; }
private:
	PaddleActor* _paddle = nullptr;
	BallActor* _ball = nullptr;
	bool _cannBallControl;
};

