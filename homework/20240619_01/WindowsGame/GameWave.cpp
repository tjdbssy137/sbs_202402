#include "pch.h"
#include "GameWave.h"
#include "BoatActor.h"

void GameWave::SetLink(vector<BoatActor*> boats)
{
	_boats = boats;

	// Add Event
	Events->AddEvent("SetGameWaveState", new GameEvent<GameWaveState>());
	Events->GetEvent<GameWaveState>("SetGameWaveState")
		->AddListen(this, &GameWave::SetGameWaveState);
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
		if (_boats.size() == 47)
		{
			_wave++;
			_boatType = 0;
			_boatCount = 0;

			//�Ǽ����� ���ư���
			GameEvent<ePanelState>* gameEvent = Events->GetEvent<ePanelState>("SetPanelState_GameStateController");
			gameEvent->Invoke(ePanelState::SHOW);
			_waveState = GameWaveState::Done;
		}
	}
		break;
	default:
		break;
	}
}
void GameWave::SetWave()
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
}