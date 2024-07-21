#pragma once
class BoatActor;

enum class GameWaveState
{
	Wave1,
	Wave2,
	Done,
};
class GameWave
{
public:
	void SetLink(vector<BoatActor*> boats);
	void Update();
public:
	void SetWave();
	void SetWave2();
public:
	void SpawnBoat(int id);
public:
	void SetGameWaveState(GameWaveState waveState) { _waveState = waveState; }
private:
	vector<BoatActor*> _boats = {};
	int _numberOfIntrusions = 0;
	GameWaveState _waveState = GameWaveState::Done;
	float _time = 1;
	int _Index = 1;

private:
	int _row = 0;
	int _column = 0;
};

