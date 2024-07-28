#pragma once
#include "RedBlockActor.h"
class BehicleActor;
class TowerDefensePanel;
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

public:
	int GetBehicleControllerIndex() { return _Index; }

	vector<Vector2Int> GetAlreadyInstallBehicle() {return _alreadyInstallBehicle; }
	void SetAlreadyInstallBehicle(vector<Vector2Int> temp) { _alreadyInstallBehicle = temp; }
	
	Vector2Int GetBehiclePos() { return _pos; }

public:
	void OnMouse();
	void OffMouse();
private:
	MouseState _mouseState = MouseState::Nothing;
	Vector2Int _pos = {};
private:
	vector<Vector2Int> _alreadyInstallBehicle = {};
	int _Index = 0;
private:
	TowerDefensePanel* _mainPanel = nullptr;
	float _textTimer = 2.0f;

};

