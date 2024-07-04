#include "pch.h"
#include "GameWave.h"
#include "BoatActor.h"
void GameWave::SetLink(vector<BoatActor*> boats)
{
	_boats = boats;
}
void GameWave::Update()
{
	switch (_waveState)
	{
	case GameWaveState::Wave1:
		SetWave();
		break;
	case GameWaveState::Wave2:
		SetWave2();
		break;
	default:
		break;
	}
}
void GameWave::SetWave()
{
	//FB_EnemyBoat2_
	//FB_EnemyShip3_
	for (int i = 0; i < 3; i++) // 거리, 시간차 있게 생성
	{
		_boats[i]->SetCellPos({ 50 + i, 25 }, true); // 거리, 시간차 있게 생성
		_boats[i]->SetBoatType(L"FB_EnemyBoat1_");
		_boats[i]->SetActiveBoat();
		_boats[i]->SetBoatHP(100);
		_boats[i]->SetBoatSpeed(50);
		_boats[i]->SetState(BoatState::Start);
	}
	_waveState = GameWaveState::Done;
}
void GameWave::SetWave2()
{
	for (int i = 0; i < 5; i++)
	{
		_boats[i]->SetBoatType(L"FB_EnemyBoat1_");
		_boats[i]->SetActiveBoat();
		_boats[i]->SetBoatHP(100);
		_boats[i]->SetBoatSpeed(50);
		_boats[i]->SetState(BoatState::Start);
	}
	for (int i = 5; i < 7; i++)
	{
		_boats[i]->SetBoatType(L"FB_EnemyBoat2_");
		_boats[i]->SetActiveBoat();
		_boats[i]->SetBoatHP(100);
		_boats[i]->SetBoatSpeed(100);
		_boats[i]->SetState(BoatState::Start);
	}
}