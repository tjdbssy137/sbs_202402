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
		int a = 0, b = 1;
		for (int i = 0; i < COUNT; i++)
		{
			BrickActor* newBrick = new BrickActor();
			
			newBrick->Init();
			float _x = newBrick->GetBody().pos.x;
			float _y = newBrick->GetBody().pos.y;

			newBrick->SetBody(CenterRect(Vector2(_x + 100 * a + 100, _y + 40 * b), 100, 30));

			a++;

			if ((i + 1) % 12 == 0)
			{
				a = 0;
				b++;
			}
			_brick.push_back(newBrick);
			this->SpawnActor(_brick[i]);
		}
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

	//InGameScene�� Update
	for (int i = 0; i < COUNT; i++)
	{
		if (_brick[i]->GetBool() == false)
		{
			this->DespawnActor(_brick[i]);
		}
	}
	
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
		//playerController����, ���콺�� �� ���۰����ϰ� ���ش�.
		//_ballActor���� _paddle���� ���� �������ش�.
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