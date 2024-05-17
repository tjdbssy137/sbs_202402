#pragma once
#include "Scene.h"
class NumberBlockActor;
class Game2048Controller;

#define INSTINATE_MAX 26
class Dev2Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void RoadResource();
private:
	vector<NumberBlockActor*> _numberBlocks;
	Game2048Controller* _game2048Controller = nullptr;
};
