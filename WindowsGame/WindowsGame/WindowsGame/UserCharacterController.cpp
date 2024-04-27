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
	this->ChangeCreatureDir();
	this->ChangeCreaturePos();

	_monster->LookAtPlayer(_creature->GetPos());

	if (_monster->GetMonsterHp() < 0)
	{
		_monster->ChangeState(MonsterState::Die);
	}

	if (Input->GetKeyDown(KeyCode::Space))
	{
		_creature->ChangeState(CreatureState::Attack);
		PlayerAttackMonster();
	}
}

Vector2 UserCharacterController::ChangeCreatureDir()
{
	if (Input->GetKey(KeyCode::Left))
	{
		_creature->SetDirState(CreatureDirectionState::Left);
		_creature->ChangeState(CreatureState::Move);
		return Vector2::Left();
	}

	if (Input->GetKey(KeyCode::Right))
	{
		_creature->SetDirState(CreatureDirectionState::Right);
		_creature->ChangeState(CreatureState::Move);
		return Vector2::Right();
	}

	if (Input->GetKey(KeyCode::Up))
	{
		_creature->SetDirState(CreatureDirectionState::Up);
		_creature->ChangeState(CreatureState::Move);
		return Vector2::Up();
	}
	
	if (Input->GetKey(KeyCode::Down))
	{
		_creature->SetDirState(CreatureDirectionState::Down);
		_creature->ChangeState(CreatureState::Move);
		return Vector2::Down();
	}

	if (_creature->GetState() != CreatureState::Attack)//°ø°ÝÀÌ ¾Æ´Ò ¶§ ¸ØÃã.
	{
		_creature->ChangeState(CreatureState::Idle);
		_monster->ChangeState(MonsterState::Idle);
	}
	return Vector2::Zero();
}

void UserCharacterController::ChangeCreaturePos()
{
	_creature->SetPos(ChangeCreatureDir() * Time->GetDeltaTime() * _speed + _creature->GetPos());
}

void UserCharacterController::PlayerAttackMonster()
{
	BoxCollider* creatureCollider = _creature->GetComponent<BoxCollider>();
	BoxCollider* monsterCollider = _monster->GetComponent<BoxCollider>();
	if (Collision::RectInRect(creatureCollider->GetCollision().ToRect(), monsterCollider->GetCollision().ToRect()))
	{
		_monster->ChangeState(MonsterState::GetHit);
		_monster->SetMonsterHp();
	}
}