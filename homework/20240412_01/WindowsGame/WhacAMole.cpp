#include "pch.h"
#include "WhacAMole.h"
#include "MoleActor.h"
#include "MoleHouseActor.h"
#include "HammerActor.h"
#include "WhacAMoleGameController.h"

void WhacAMole::Init()
{
	Super::Init();
	{
		{//�δ��� ��
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 4; j++)
				{
					MoleHouseActor* moleHouse = new MoleHouseActor();
					moleHouse->Init();
					moleHouse->SetName("moleHouse");
					moleHouse->SetBody(CenterRect(Vector2(200 + (j * 120), 150 + (i * 120)), 100, 100));
					_moleHouse.push_back(moleHouse);
					this->SpawnActor(_moleHouse.back());
				}
			}
		}

		{//�δ���
			for (int i = 1; i <= 3; i++)
			{
				for (int j = 1; j <= 4; j++)
				{
					MoleActor* mole = new MoleActor();
					mole->Init();
					mole->SetName("mole");
					mole->SetBody(CenterRect(Vector2(200 + (j * 120), 150 + (i * 120)), 100, 100));
					_mole.push_back(mole);
					this->SpawnActor(_mole.back());
				}
			}
		}

		{//��ġ
			_hammer = new HammerActor();
			_hammer->Init();
			_hammer->SetName("hammer");
			this->SpawnActor(_hammer);
		}

		{//_whacAMoleGameController
			_whacAMoleGameController = new WhacAMoleGameController();
			_whacAMoleGameController->Init(_hammer);
		}
	}

	_playTime = 60;
	this->ChangeGameState(GameState::Wait);
	srand(time(NULL));
}
void WhacAMole::Render(HDC hdc) {
	Super::Render(hdc);
	wstring str = L"WhacAMole";
	::TextOut(hdc, 0, 45, str.c_str(), str.length());

	wstring timeStr = format(L"Timer : {0:*>.1f}", _playTime);
	::TextOut(hdc, 0, 75, timeStr.c_str(), timeStr.length());

	wstring pointStr = format(L"Caught Mole : {0}", _point);
	::TextOut(hdc, 0, 90, pointStr.c_str(), pointStr.length());
}
void WhacAMole::Update()
{
	Super::Update();
	_whacAMoleGameController->Update();
	// playState�� ���
	if (_whacAMoleGameController->GetCanHammerController() == true)
	{
		this->TimeToComingMole(0.5f);
		//this->Timer(0.7f); // 3.5�� �뿣 ���ÿ� ����� �ٷ��µ� �� ��..

		if (Input->GetKeyDown(KeyCode::LeftMouse))
		{
			for (int i = 0; i < 12; i++)
			{
				if (_mole[i]->GetIsCollision() == true)
				{
					_point++;
					//�ι�Ŭ�������ؾ���.
				}
			}
		}
		_playTime -= Time->GetDeltaTime();
	}

	//���� 60�ʵ��ȸ� �� �� ����.
	if (_playTime < 0)
	{
		this->ChangeGameState(GameState::Wait);
	}
}
void WhacAMole::Release()
{
	Super::Release();
}

void WhacAMole::TimeToComingMole(float time)
{
	_time += Time->GetDeltaTime();
	if (time < _time)
	{
		//���ʵڿ����������
		//�δ��� ����� ����� �������ŭ �����ϰ� collider�� 0,0,0,0 ���� ����ų� ontriggerenter�� ���� �Լ��� �����.
		int random = rand() % 12;
		while (random == _used)
		{
			random = rand() % 12;
		}

		_mole[random]->MoleGetsBigger(_mole[random]->GetBody().ToRect());

		if (time + 0.3f < _time)
		{
			_mole[random]->MoleGetsSmaller(_mole[random]->GetBody().ToRect());
			_time = 0;
		}
		_used = random;
	}
}

void WhacAMole::ChangeGameState(GameState state)
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
		_whacAMoleGameController->SetCanHammerController(false);
		break;

	case GameState::Play:
		_point = 0;
		_playTime = 60;
		_whacAMoleGameController->SetCanHammerController(true);
		break;
	}
}