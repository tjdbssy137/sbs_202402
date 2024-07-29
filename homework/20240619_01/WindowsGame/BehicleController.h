#pragma once
class BehicleActor;

class BehicleController
{
private:
	BehicleActor* _behicle = nullptr;
public:
	void SetLink(BehicleActor* behicle);
	void Update();

public:
	void SettingBehicle(int id);
	void DeleteBehicle();
public:
	BehicleData GetBehicleData() { return _data; }

private:
	BehicleData _data;
};