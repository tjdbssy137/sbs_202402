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
void GameWave::SetWave() //���̽����� ����
{
	static float lastTick = ::GetTickCount64(); //��� ȣ�⿡�� ����
	WaveData data = Datas->GetWaveData(_wave);

	if (_boatType < data.BoatCount.size())
	{
		if (_boatCount < data.BoatCount[_boatType])
		{
			float currentTick = ::GetTickCount64();
			if (SPAWN_TIME < currentTick - lastTick)
			{
				SpawnBoat(Datas->GetBoatData(_boatType + 1));
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
void GameWave::SpawnBoat(BoatData data)
{
	BoatActor* boat = _boats.back();
	_boats.pop_back();
	boat->SetBoatData(data);
	boat->SetActiveBoat();
	boat->ChangeDirection(eDirection::DOWN_RIGHT); // ������ �ѹ� ��ȯ ����� �̹����� ���� ������Ʈ ��.
	boat->SetState(BoatState::Start);
	//cout << "hi" << endl; // ������ �Ǵµ� �� ����, 
						// behicle���� ������ �� ������ ������ ��� �� �Ǵµ�, ������ �׵ڷκ��� ������ �� �ȵ�
	/*
	wstring name = wstring().assign(data.Name.begin(), data.Name.end());
	boat->SetBoatType(name);
	boat->SetActiveBoat();
	boat->SetBoatHp(Datas->GetBoatData(id).HP);
	boat->SetBoatStaticHp(Datas->GetBoatData(id).HP);
	boat->SetBoatSpeed(Datas->GetBoatData(id).MoveSpeed);
	boat->ChangeDirection(eDirection::DOWN_RIGHT); // ������ �ѹ� ��ȯ ����� �̹����� ���� ������Ʈ ��.
	boat->SetState(BoatState::Start);
	*/
}