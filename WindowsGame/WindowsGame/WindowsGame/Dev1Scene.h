#pragma once
#include "Scene.h"
class CreatureActor;
class MonsterActor;
class UserCharacterController;
class Dev1Scene : public Scene
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
	CreatureActor* _creature = nullptr;
	MonsterActor* _monster = nullptr;
	UserCharacterController* _userCharacterController = nullptr;
};

