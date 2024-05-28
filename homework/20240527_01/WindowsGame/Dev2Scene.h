#pragma once
#include "Scene.h"
class CreatureActor;

class Panel;
class Dev2Scene : public Scene
{
	using Super = Scene;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;
public:
	void LoadResource();

private:
	Panel* panel = nullptr;
	CreatureActor* _creature = nullptr;

};

