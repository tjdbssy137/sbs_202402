#include "pch.h"
#include "InGameScene.h"

#include "BrickActor.h"
#include "BallActor.h"
#include "PaddleActor.h"
#include "PlayerController.h"
#include "InGameState.h"

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
		_gameState = new InGameState();
	}
	this->ChangeGameState(GameState::None);

}
void InGameScene::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"InGameScene";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring gameStateStr = format(L"GameState : {0}", (int)_gameState);
	::TextOut(hdc, 0, 45, gameStateStr.c_str(), gameStateStr.length());
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
	//state ���� ���� -> ������ ����
	switch (_gameState->GetGameState())
	{
	case GameState::None:
		// playerController����, ���콺�� ���� �����ϰ� ���ش�.
		// ballActor���� _paddle ���� ���� �������ش�.
		break;
	case GameState::Wait:
		_playerController->SetCanBallController(true);

		Vector2 paddlePos = _paddle->GetBody()->pos;
		float paddleHeight = _paddle->GetBody().height;
		paddlePos.y -= _ball->GetBody().height + paddleHeight/2;
		_ball->SetPos(paddlePos);
		_ball->SetMoveDir(Vector2::Zero);
		break;
	case GameState::Play:
		_playerController->SetCanBallController(false);
		break;
	}
}