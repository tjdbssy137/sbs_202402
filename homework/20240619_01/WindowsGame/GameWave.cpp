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
	case GameWaveState::Done:
		_Index = 0;
		break;
	default:
		break;
	}
}
void GameWave::SetWave() //제이슨으로 변경
{
	//FB_EnemyBoat2_
	//FB_EnemyShip3_
	static float lastTick = ::GetTickCount64(); //모든 호출에서 공유

	if (_Index < 3)
	{
		float currentTick = ::GetTickCount64();
		if (1000 < currentTick - lastTick)
		{
			_boats[_Index]->SetBoatType(L"FB_EnemyBoat1_");
			_boats[_Index]->SetActiveBoat();
			_boats[_Index]->SetBoatHP(60);
			_boats[_Index]->SetBoatStaticHP(60);
			_boats[_Index]->SetBoatSpeed(50);
			_boats[_Index]->SetState(BoatState::Start);
			lastTick = currentTick;
			_Index++;
		}
	}
	else
	{
		_waveState = GameWaveState::Done;
	}
}
void GameWave::SetWave2()
{
	static float lastTick = ::GetTickCount64(); //모든 호출에서 공유

	if (_Index < 5)
	{
		float currentTick = ::GetTickCount64();
		if (1000 < currentTick - lastTick)
		{
			_boats[_Index]->SetBoatType(L"FB_EnemyBoat1_");
			_boats[_Index]->SetActiveBoat();
			_boats[_Index]->SetBoatHP(60);
			_boats[_Index]->SetBoatStaticHP(60); 
			_boats[_Index]->SetBoatSpeed(50);
			_boats[_Index]->SetState(BoatState::Start);
			lastTick = currentTick;
			_Index++;
		}
	}
	else if (_Index < 8)
	{
		float currentTick = ::GetTickCount64();
		if (1000 < currentTick - lastTick)
		{
			_boats[_Index]->SetBoatType(L"FB_EnemyBoat2_");
			_boats[_Index]->SetActiveBoat();
			_boats[_Index]->SetBoatHP(80);
			_boats[_Index]->SetBoatStaticHP(80); 
			_boats[_Index]->SetBoatSpeed(100);
			_boats[_Index]->SetState(BoatState::Start);
			lastTick = currentTick;
			_Index++;
		}
	}
	else
	{
		_waveState = GameWaveState::Done;
	}
}