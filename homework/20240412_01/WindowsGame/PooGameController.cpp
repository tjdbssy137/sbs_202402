#include "pch.h"
#include "PooGameController.h"
#include "PooActor.h"
#include "PlayerActor.h"
#include "PooGame.h"

void PooGameController::Init(PlayerActor* player, vector<PooActor*> poo)
{
	_player = player;
	_poo = poo;
}

void PooGameController::Update()
{
	if (_canPlayerControl == true)
	{
		if (Input->GetKey(KeyCode::A))
		{
			_player->Move(Vector2::Left());
		}
		if (Input->GetKey(KeyCode::D))
		{
			_player->Move(Vector2::Right());
		}

		if (_player->GetBody().pos.x < 300)
		{
			_player->SetBody(CenterRect(Vector2(301, 700), 60, 40));
		}
		if (900 < _player->GetBody().pos.x)
		{
			_player->SetBody(CenterRect(Vector2(899, 700), 60, 40));
		}

		for (int i = 0; i < POO_MAX; i++)
		{
			_poo[i]->Move();
		}
	}
	else
	{
		if (Input->GetKeyDown(KeyCode::RightMouse))
		{
			PooGame* currentScene = dynamic_cast<PooGame*>(GET_SINGLE(SceneManager)->GetCurrentScene());
			if (currentScene != nullptr)
			{
				currentScene->ChangeGameState(GameState::Play);
			}
		}
	}
}