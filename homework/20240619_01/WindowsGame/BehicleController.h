#pragma once
class BehicleActor;

enum class BehicleTypeState
{
	DrillTank1,
	DrillTank2,
	DrillTank3,
	Tank1,
	Tank2,
	Tank3,
	Submarine,
	None,
	Delete
};
class BehicleController
{
private:
	BehicleActor* _behicle = nullptr;
public:
	void SetLink(BehicleActor* behicle);
	void Update();

public:
	void SettingBehicle(BehicleData data);
public:

	BehicleTypeState GetBehicleTypeState() { return _type; }
	void SetBehicleTypeState(int type) { _type = static_cast<BehicleTypeState>(type); }
	void IsSetting(bool isSetting) { _isSetting = isSetting; }
private:
	BehicleTypeState _type = BehicleTypeState::Tank1;
	bool _isSetting = false;
};