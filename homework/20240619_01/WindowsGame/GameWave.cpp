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
	case GameWaveState::Wave:
		SetWave();
		break;
	case GameWaveState::Break:
	{
		_wave++;
		_boatType = 0;
		_boatCount = 0;
		_waveState = GameWaveState::Done;
	}
		break;
	default:
		break;
	}
}
void GameWave::SetWave() //제이슨으로 변경
{
	static float lastTick = ::GetTickCount64(); //모든 호출에서 공유
	WaveData data = Datas->GetWaveData(_wave);

	if (_boatType < data.BoatCount.size())
	{
		if (_boatCount < data.BoatCount[_boatType])
		{
			float currentTick = ::GetTickCount64();
			if (SPAWN_TIME < currentTick - lastTick)
			{
				SpawnBoat(Datas->GetBoatData(_boatType + 1).Id);
				_boatCount++;
				lastTick = currentTick;
			}
		}
		if (_boatCount == data.BoatCount[_boatType])
		{
			_boatCount = 0;
			_boatType++;

			if (data.BoatCount.size() <= _boatType)
			{
				_waveState = GameWaveState::Break;
			}
			else if (data.BoatCount[_boatType] == 0)
			{
				_waveState = GameWaveState::Break;
			}
		}
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
	boat->ChangeDirection(eDirection::DOWN_RIGHT); // 방향을 한번 전환 해줘야 이미지가 새로 업데이트 됨.
	boat->SetState(BoatState::Start);
}