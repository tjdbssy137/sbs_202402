#pragma once

class CreatureActor;
class MonsterActor;
class UserCharacterController
{
public:
	void Init(CreatureActor* creature, MonsterActor* monster);
	void Update();

	void ChangeCreaturePos();
	Vector2 ChangeCreatureDir();
	void PlayerAttackMonster();
private:
	CreatureActor* _creature = nullptr;
	MonsterActor* _monster = nullptr;
	float _speed = 200;
	float _time = 1;
};

