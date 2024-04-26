#pragma once

class CreatureActor;

class UserCharacterController
{
public:
	void Init(CreatureActor* creature);
	void Update();

	void ChangeCreaturePos();
	Vector2 ChangeCreatureDir();
	void AttacCreature();

private:
	CreatureActor* _creature = nullptr;
	float _speed = 200;
};

