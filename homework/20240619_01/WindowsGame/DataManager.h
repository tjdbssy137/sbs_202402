#pragma once

enum class DataType
{
	Wave,
	Behicle,
	Boat
};
class DataManager
{
	DECLARE_SINGLE(DataManager);
public:
	void Init();
	void Release();

	MonsterData GetMonster(int64 id) { return _monsterDatas[id]; }

public:
	void LoadData(wstring loadData, DataType dataType);

	// Tower Defense
	WaveData GetWaveData(int64 id) { return _waveDatas[id]; }
	BehicleData GetBehicleData(int64 id) { return _behicleDatas[id]; }
	BoatData GetBoatData(int64 id) { return _boatDatas[id]; }
private:
	//vector<MonsterData> _monsterDatas = {};
	map<int64, MonsterData> _monsterDatas = {};

	// Tower Defense
	map<int64, WaveData> _waveDatas = {};
	map<int64, BehicleData> _behicleDatas = {};
	map<int64, BoatData> _boatDatas = {};

};

