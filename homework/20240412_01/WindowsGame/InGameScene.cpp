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
		_brick = new BrickActor();

		_brick->Init();

		this->SpawnActor(_brick);
	}

	{
		_paddle = new PaddleActor();
		_paddle->Init();
		this->SpawnActor(_paddle);

		_paddlePos = _paddle->GetBody().pos;
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

		_paddle->SetPos(_paddlePos);
		float paddleHeight = _paddle->GetBody().height;
		_paddlePos.y -= _ball->GetBody().height / 2 + paddleHeight / 2;
		_ball->SetPos(_paddlePos);
		_ball->SetMoveDir(Vector2::Zero());
	}
	break;
	case GameState::Play:
		_playerController->SetCanBallController(false);
		break;
	}
}