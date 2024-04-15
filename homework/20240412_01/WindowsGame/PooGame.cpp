#include "pch.h"
#include "PooGame.h"
#include "PlayerActor.h"
#include "PooActor.h"
#include "BoxCollider.h"
#include "PooGameController.h"

/// <summary>
/// 똥피하기게임
/// </summary>
void PooGame::Init()
{
	Super::Init();

	{
		player = new PlayerActor();
		player->Init();
		player->SetName("플레이어");
		this->SpawnActor(player);
	}

	{
		for (int i = 0; i < isActive; i ++)
		{
			PooActor* poo = new PooActor();
			poo->Init();
			poo->SetName("Poo");
			_poo.push_back(poo);
			this->SpawnActor(_poo[i]);
		}
	}

	{
		for (int i = 0; i < isActive; i++)
		{
			_isActive[i] = true;
		}
	}

	{
		pooGameController = new PooGameController();
		pooGameController->Init(player);
	}

	srand(time(NULL));
	this->ChangeGameState(GameState::Wait);

}
void PooGame::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"PooGame";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring survivalTime = format(L"Survival time : {0}", _survivalTime);
	::TextOut(hdc, 0, 90, survivalTime.c_str(), survivalTime.length());

	if (pooGameController->GetCanPlayerControl() == false)
	{
		wstring survival = L"Game Over";
		::TextOut(hdc, 0, 135, survival.c_str(), survival.length());
	}
}
void PooGame::Update()
{
	Super::Update();

	pooGameController->Update();
	
	if (pooGameController->GetCanPlayerControl() == true)
	{
		_survivalTime += Time->GetDeltaTime();
	}

	{
		_time += Time->GetDeltaTime();
		if (0.5f <= _time)
		{
			int random = rand() % isActive;
			if (_isActive[random] == true)
			{
				_isActive[random] = false;
				int _pooPosX = rand() % 600 + 300;
				_poo[random]->Throw(_pooPosX, 700);
			}
			_time = 0;
		}
	}

	{
		for (int i = 0; i < isActive; i++)
		{
			if (700 < _poo[i]->GetBody().pos.y)
			{
				_isActive[i] = true;
			}
		}
	}
	
}
void PooGame::Release()
{
	Super::Release();
}

void PooGame::ChangeGameState(GameState state)
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
		pooGameController->SetCanPlayerController(false);
	break;

	case GameState::Play:
		pooGameController->SetCanPlayerController(true);
		_survivalTime = 0;
		player->SetPos(Vector2(WIN_SIZE_X / 2, 700));
		break;
	}
}