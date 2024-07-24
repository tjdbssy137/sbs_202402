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

public:
	void LoadData(wstring loadData, DataType dataType);

	// Tower Defense
	WaveData GetWaveData(int64 id) { return _waveDatas[id]; }
	BehicleData GetBehicleData(int64 id) { return _behicleDatas[id]; }
	BoatData GetBoatData(int64 id) { return _boatDatas[id]; }
private:
	// Tower Defense
	map<int64, WaveData> _waveDatas = {};
	map<int64, BehicleData> _behicleDatas = {};
	map<int64, BoatData> _boatDatas = {};

};

