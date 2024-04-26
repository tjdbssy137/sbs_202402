#include "pch.h"
#include "UserCharacterController.h"
#include "CreatureActor.h"

void UserCharacterController::Init(CreatureActor* creature)
{
	_creature = creature;
}
void UserCharacterController::Update()
{
	this->ChangeCreatureDir();
	this->ChangeCreaturePos();

	if (Input->GetKeyDown(KeyCode::Space))
	{
		_creature->ChangeState(CreatureState::Attack);
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

	if (false == (Input->GetKeyDown(KeyCode::Space)))//°ø°ÝÀÌ ¾Æ´Ò ¶§ ¸ØÃã.
	{
		_creature->ChangeState(CreatureState::Idle);
	}
	return Vector2::Zero();
}


void UserCharacterController::ChangeCreaturePos()
{
	_creature->SetPos(ChangeCreatureDir() * Time->GetDeltaTime() * _speed + _creature->GetPos());
}
/*
void UserCharacterController::AttacCreature()
{
	_creature->DoAttack(ChangeCreatureDir());
}
*/