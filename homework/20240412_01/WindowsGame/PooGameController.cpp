#include "pch.h"
#include "PooGameController.h"
#include "PooActor.h"
#include "PlayerActor.h"
#include "PooGame.h"

void PooGameController::Init(PlayerActor* player)
{
	_player = player;
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