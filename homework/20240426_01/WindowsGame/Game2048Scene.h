#pragma once
#include "Scene.h"
class NumberRectActor;

#define INSTINATE_MAX 26

class Game2048Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	vector<NumberRectActor*> _numberRects;
};