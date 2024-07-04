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
	void SetGameWaveState(GameWaveState waveState) { _waveState = waveState; }
private:
	vector<BoatActor*> _boats = {};
	int _numberOfIntrusions = 0;
	GameWaveState _waveState = GameWaveState::Done;
};

