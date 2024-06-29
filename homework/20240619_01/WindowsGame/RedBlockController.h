#pragma once
#include "RedBlockActor.h"
enum class MouseState
{
	Move,
	Click,
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
	void DoInstallBehicle();

private:
	MouseState _mouseState = MouseState::Nothing;
	Vector2Int _pos = {};
};
