#pragma once
class CreatureActor;
class CreatureController
{
private:
	CreatureActor* _actor;
	float _trueTime = 0.135f;
public:
	void SetLink(CreatureActor* actor);
	void Update();
};

