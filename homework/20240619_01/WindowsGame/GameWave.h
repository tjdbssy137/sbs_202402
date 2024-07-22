#pragma once
class BoatActor;
#define SPAWN_TIME 1000
enum class GameWaveState
{
	Wave,
	Break,
	Done
};
class GameWave
{
public:
	void SetLink(vector<BoatActor*> boats);
	void Update();
public:
	void SetWave();
public:
	void SpawnBoat(BoatData data);
public:
	void SetGameWaveState(GameWaveState waveState) { _waveState = waveState; }
public:
	void PushBoatActor(BoatActor* boat) { _boats.push_back(boat); }

private:
	vector<BoatActor*> _boats = {};
	GameWaveState _waveState = GameWaveState::Done;
	int _wave = 1; // 1~6
	int _boatType = 0;
	int _boatCount = 0;
};

