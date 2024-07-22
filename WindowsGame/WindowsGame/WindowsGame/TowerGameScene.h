#pragma once
#include "Scene.h"
class TowerGameScene : public Scene
{
	DECLARE_CHILD(TowerGameScene, Scene);
public:
	virtual void Init() override;
	virtual void Render(HDC hdc)override;
	virtual void Update()override;
	virtual void Release()override;
private:
	void LoadResource();

};

