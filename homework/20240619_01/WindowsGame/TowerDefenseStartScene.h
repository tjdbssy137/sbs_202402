#pragma once
#include "Scene.h"
class TowerDefenseStartScene : public Scene
{
	DECLARE_CHILD(TowerDefenseStartScene, Scene);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
};

