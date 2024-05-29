#pragma once
class CreatureActor;
class CreatureController
{
private:
	CreatureActor* _actor = nullptr;
public:
	void SetLink(CreatureActor* actor);
	void Update();

};