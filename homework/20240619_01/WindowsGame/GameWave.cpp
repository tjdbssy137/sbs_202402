#include "pch.h"
#include "GameWave.h"
#include "BoatActor.h"
#include "Dev2Scene.h"

void GameWave::SetLink(vector<BoatActor*> boats)
{
	_boats = boats;
}
void GameWave::Update()
{
	//cout << "Datas->GetBoatData(2).Id : " << Datas->GetBoatData(2).Id << endl;

	switch (_waveState)
	{
	case GameWaveState::Wave1:
		SetWave();
		break;
	case GameWaveState::Wave2:
		SetWave2();
		break;
	case GameWaveState::Done:
	{
		_Index = 0;
		_row = 0;
		_column = 0;
	}
		break;
	default:
		break;
	}
}
void GameWave::SetWave() //제이슨으로 변경
{
	static float lastTick = ::GetTickCount64(); //모든 호출에서 공유
	if (_row < Datas->GetWaveData(1).BoatCount.size())
	{
		if (_column <= Datas->GetWaveData(1).BoatCount[_row])
		{
			float currentTick = ::GetTickCount64();
			if (1000 < currentTick - lastTick)
			{
				SpawnBoat(Datas->GetBoatData(_row + 1).Id);
				lastTick = currentTick;
				_column++;
			}
		}
		if (_column == Datas->GetWaveData(1).BoatCount[_row])
		{
			_column = 0;
			_row++;

			if (Datas->GetWaveData(1).BoatCount[_row] == 0)
			{
				_waveState = GameWaveState::Done;
			}
		}
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
			SpawnBoat(Datas->GetBoatData(1).Id);
			/*_boats[_Index]->SetBoatType(L"FB_EnemyBoat1_");
			_boats[_Index]->SetActiveBoat();
			_boats[_Index]->SetBoatHp(60);
			_boats[_Index]->SetBoatStaticHp(60); 
			_boats[_Index]->SetBoatSpeed(50);
			_boats[_Index]->SetState(BoatState::Start);*/
			lastTick = currentTick;
			_Index++;
		}
	}
	else if (_Index < 8)
	{
		float currentTick = ::GetTickCount64();
		if (1000 < currentTick - lastTick)
		{
			SpawnBoat(Datas->GetBoatData(2).Id);
			
			/*_boats[_Index]->SetBoatType(L"FB_EnemyBoat2_");
			_boats[_Index]->SetActiveBoat();
			_boats[_Index]->SetBoatHp(80);
			_boats[_Index]->SetBoatStaticHp(80); 
			_boats[_Index]->SetBoatSpeed(100);
			_boats[_Index]->SetState(BoatState::Start);*/
			lastTick = currentTick;
			_Index++;
		}
	}
	else
	{
		_waveState = GameWaveState::Done;
	}
}

void GameWave::SpawnBoat(int id)
{
	BoatActor* boat = _boats.back();
	_boats.pop_back();
	BoatData data = Datas->GetBoatData(id);
	wstring name = wstring().assign(data.Name.begin(), data.Name.end());

	boat->SetBoatType(name);
	boat->SetActiveBoat();
	boat->SetBoatHp(Datas->GetBoatData(id).HP);
	boat->SetBoatStaticHp(Datas->GetBoatData(id).HP);
	boat->SetBoatSpeed(Datas->GetBoatData(id).MoveSpeed);
	boat->SetState(BoatState::Start);
}