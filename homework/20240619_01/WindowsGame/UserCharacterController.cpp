#include "pch.h"
#include "UserCharacterController.h"
#include "CreatureActor.h"
#include "MonsterActor.h"
#include "BoxCollider.h"

void UserCharacterController::Init(CreatureActor* creature, MonsterActor* monster)
{
	_creature = creature;
	_monster = monster;
	
}
void UserCharacterController::Update()
{
	_monster->LookAtPlayer(_creature->GetPos());
	/*
	if (_monster->GetMonsterHp() < 0)
	{
		_monster->SetState(MonsterState::Die);
	}
	*/
	if (_creature->GetState() == CreatureState::Attack)
	{
		PlayerAttackMonster();
	}
}

void UserCharacterController::PlayerAttackMonster()
{
	BoxCollider* creatureCollider = _creature->GetComponent<BoxCollider>();
	BoxCollider* monsterCollider = _monster->GetComponent<BoxCollider>();
	if (Collision::RectInRect(creatureCollider->GetCollision().ToRect(), monsterCollider->GetCollision().ToRect()))
	{
		_monster->SetState(MonsterState::GetHit);
		_monster->SetMonsterHp();
	}
}