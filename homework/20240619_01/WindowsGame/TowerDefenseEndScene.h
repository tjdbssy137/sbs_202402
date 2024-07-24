#pragma once
#include "Scene.h"
class TowerDefenseEndScene : public Scene
{
	DECLARE_CHILD(TowerDefenseEndScene, Scene);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

