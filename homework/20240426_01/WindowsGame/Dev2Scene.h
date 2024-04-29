#pragma once
#include "Scene.h"

class BadukActor;
class Dev2Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

private:
	vector<BadukActor*> _whiteBaduks;
	vector<BadukActor*> _blackBaduks;
};

