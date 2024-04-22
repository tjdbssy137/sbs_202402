#pragma once
#include "Scene.h"
class Dev1Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
private:
	CenterRect _player;
	Vector2 _playerDir;
	Vector2 _targetPos = { -1, -1 };

private:
	CenterRect _wall = {};
};
