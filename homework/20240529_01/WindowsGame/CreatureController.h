#pragma once
class CreatureActor;
class CreatureController
{
private:
	CreatureActor* _actor;

public:
	void SetLink(CreatureActor* actor);
	void Update();
};

