#pragma once
#include "RedBlockActor.h"
class BehicleActor;
enum class MouseState
{
	Move,
	ClickGround,
	ClickOcean,
	UpgradeDelete,
	Nothing
};

class RedBlockController
{
private:
	RedBlockActor* _block = nullptr;
public:
	void SetLink(RedBlockActor* block);
	void Update();
public:
	void CanInstallBehicle();
	void DoInstallGround();
	void DoInstallOcean();
	Vector2Int GetInstallBehiclePos() { return _pos; }

	void DoUpgradeDeleteBehicle();

	BehicleActor* GetBehicleActor() { return _returnBehicle; }
	int GetBehicleControllerIndex() { return _Index; }

	vector<Vector2Int> GetAlreadyInstallBehicle() {return _alreadyInstallBehicle; }
	void SetAlreadyInstallBehicle(vector<Vector2Int> temp) { _alreadyInstallBehicle = temp; };
	
	Vector2Int GetBehiclePos() { return _pos; }
private:
	MouseState _mouseState = MouseState::Nothing;
	Vector2Int _pos = {};
private:
	vector<Vector2Int> _alreadyInstallBehicle = {};
	BehicleActor* _returnBehicle = nullptr;
	int _Index = 0;
};

