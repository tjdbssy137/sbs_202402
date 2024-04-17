#include "pch.h"
#include "WhacAMoleGameController.h"
#include "HammerActor.h"
#include "WhacAMole.h"

void WhacAMoleGameController::Init(HammerActor* hammer)
{
	_hammer = hammer;
}

void WhacAMoleGameController::Update()
{
	if (_canHammerControl == true)
	{
		_hammer->SetUseHammer(true);
	}
	else
	{
		_hammer->SetUseHammer(false);

		if (Input->GetKeyDown(KeyCode::LeftMouse))
		{
			WhacAMole* currentScene = dynamic_cast<WhacAMole*>(GET_SINGLE(SceneManager)->GetCurrentScene());
			if (currentScene != nullptr)
			{
				currentScene->ChangeGameState(GameState::Play);
			}
		}
	}
}
