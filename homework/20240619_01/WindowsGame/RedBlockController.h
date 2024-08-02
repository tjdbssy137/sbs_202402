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
	void DoUpgradeDeleteBehicle();

public:
	int GetBehicleControllerIndex() { return _Index; }
	Vector2Int GetInstallBehiclePos() { return _pos; }

public:
	void RemoveAlreadyInstallPos(Vector2Int pos);
	void RemoveAlreadyInstallPos();

	void OnMouse();
	void OffMouse();
private:
	MouseState _mouseState = MouseState::Nothing;
	Vector2Int _pos = {};
private:
	vector<Vector2Int> _alreadyInstallBehicle = {};
	int _Index = 0;
};

