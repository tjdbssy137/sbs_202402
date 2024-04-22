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
		for (int i = 0; i < POO_MAX; i ++)
		{
			PooActor* poo = new PooActor();
			poo->Init();
			poo->SetName("Poo");
			_poo.push_back(poo);
			this->SpawnActor(_poo[i]);
		}
	}

	{
		for (int i = 0; i < POO_MAX; i++)
		{
			_isRun[i] = true;
		}
	}

	{
		_pooGameController = new PooGameController();
		_pooGameController->Init(player, _poo);
	}

	this->ChangeGameState(GameState::Wait);

	srand(time(NULL));
	_tempTime = 20;
	_throwTime = 0.5f;
}
void PooGame::Render(HDC hdc) {
	Super::Render(hdc);

	wstring str = L"PooGame";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring survivalTime = format(L"Survival time : {0:*>.1f}\t Level : {1}", _survivalTime, _level);
	::TextOut(hdc, 0, 90, survivalTime.c_str(), survivalTime.length());

	if (_pooGameController->GetCanPlayerControl() == false)
	{
		wstring survival = L"Game Over";
		::TextOut(hdc, 0, 75, survival.c_str(), survival.length());
	}
}
void PooGame::Update()
{
	Super::Update();

	_pooGameController->Update();
	
	if (_pooGameController->GetCanPlayerControl() == true)
	{
		_survivalTime += Time->GetDeltaTime();
		if (_tempTime < _survivalTime)
		{
			_tempTime *= 1.2f;
			_throwTime -= 0.05f;
			_level++;
			if (_throwTime < 0.2f)
			{
				cout << "Game Win" << endl;
			}
		}
	
		_time += Time->GetDeltaTime();
		if (_throwTime <= _time)
		{
			int random = rand() % POO_MAX;
			if (_isRun[random] == true)
			{
				_isRun[random] = false;
				int _pooPosX = rand() % 600 + 300;
				_poo[random]->Throw(_pooPosX, 700);
			}
			_time = 0;
		}
	}

	{
		for (int i = 0; i < POO_MAX; i++)
		{
			if (750 < _poo[i]->GetBody().pos.y)
			{
				_isRun[i] = true;
				_poo[i]->SetMoveDir(Vector2::Zero());
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
		_pooGameController->SetCanPlayerController(false);
	break;

	case GameState::Play:
		_pooGameController->SetCanPlayerController(true);
		_survivalTime = 0;
		_tempTime = 20;
		_throwTime = 0.5f;
		_level = 1;
		for (int i = 0; i < POO_MAX; i++)
		{
			_poo[i]->SetBody(CenterRect(Vector2(WIN_SIZE_X / 2, -50), 50, 50));
		}
		player->SetPos(Vector2(WIN_SIZE_X / 2, 700));
		break;
	}
}