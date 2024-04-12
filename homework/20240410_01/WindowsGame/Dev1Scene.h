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
	Vector2 _playerDir;
	Vector2 _targetPos;
	Vector2 _ballPos;


private:
	CenterRect _wall = {};
};

