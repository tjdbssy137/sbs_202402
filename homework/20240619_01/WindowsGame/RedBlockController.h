#pragma once
#include "RedBlockActor.h"
enum class MouseState
{
	Move,
	ClickGround,
	ClickOcean,
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
private:
	MouseState _mouseState = MouseState::Nothing;
	Vector2Int _pos = {};
};

