#pragma once
#include "Scene.h"
class NumberBlockActor;
class Game2048Controller;

#define INSTINATE_MAX 26

class Game2048Scene : public Scene
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
	vector<NumberBlockActor*> _blockTest;
	Game2048Controller* _game2048Controller = nullptr;
};

