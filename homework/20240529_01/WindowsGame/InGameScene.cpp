#include "pch.h"
#include "InGameScene.h"
#include "BrickActor.h"
#include "BallActor.h"
#include "PaddleActor.h"
#include "PlayerController.h"
#include "BoxCollider.h"

void InGameScene::Init()
{
	Super::Init();

	{
		_paddle = new PaddleActor();
		_paddle->Init();
		this->SpawnActor(_paddle);
	}

	{
		_ball = new BallActor();
		_ball->Init();
		this->SpawnActor(_ball);
	}

	{
		_playerController = new PlayerController();
		_playerController->Init(_paddle, _ball);
	}

	{
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				BrickActor* brick = new BrickActor();
				brick->Init();
				brick->SetBody(Shape::MakeCenterRectLTWH(i * 45, j * 22, 45, 22));
				this->SpawnActor(brick);
			}
		}
	}

	this->ChangeGameState(GameState::Wait);

}
void InGameScene::Render(HDC hdc)
{
	Super::Render(hdc);

	wstring str = L"InGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());


	wstring gameStateStr = format(L"GameState : {0}", (int)_gameState);
	::TextOut(hdc, 0, 60, gameStateStr.c_str(), gameStateStr.length());
}
void InGameScene::Update()
{
	Super::Update();

	_playerController->Update();
}
void InGameScene::Release()
{
	Super::Release();
}

void InGameScene::ChangeGameState(GameState state)
{
	if (_gameState == state)
	{
		return;
	}

	_gameState = state;

	switch (_gameState)
	{
	case GameState::None:
		break;

	case GameState::Wait:
	{
		//playerController한테, 마우스로 볼 조작가능하게 해준다.
		//_ballActor한테 _paddle위로 가게 세팅해준다.
		_playerController->SetCanBallController(true);

		Vector2 paddlePos = _paddle->GetBody().pos;
		float paddleHeight = _paddle->GetBody().height;
		paddlePos.y -= _ball->GetBody().height/2 + paddleHeight/2;
		_ball->SetPos(paddlePos);
		_ball->SetMoveDir(Vector2::Zero());
	}
		break;
	case GameState::Play:
		_playerController->SetCanBallController(false);
		break;
	}
}