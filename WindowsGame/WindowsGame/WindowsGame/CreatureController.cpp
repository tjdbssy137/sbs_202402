#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"

void CreatureController::SetLink(CreatureActor* actor)
{
	assert(actor != nullptr);
	_actor = actor;
}
void CreatureController::Update()
{
	_actor->SetIsAttackInput(false);
	Vector2 newVelocity = _actor->GetVelocity();
	bool isMoveKeyInput = false;
	
	if (Input->GetKey(KeyCode::Left))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::Left);
		newVelocity.x -= 88;//Time->GetDeltaTime() * 1.0f; // 1�ʸ��� ����.
		// tileMap size ��ŭ �̵�
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f); // newVelocity.x�� ������ -1.0f ~ 1.0f�� ������Ų��.
		newVelocity.y = 0;
		_actor->SetVelocity(newVelocity);
	}

	else if (Input->GetKey(KeyCode::Right))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::Right);
		newVelocity.x += 88;//Time->GetDeltaTime() * 1.0f; // 1�ʸ��� ����.
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newVelocity.y = 0;
		_actor->SetVelocity(newVelocity);
	}

	else if (Input->GetKey(KeyCode::Up))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::Up);
		newVelocity.y -= 88; //Time->GetDeltaTime() * 1.0f; // 0.5�ʸ��� ����.
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newVelocity.x = 0;
		_actor->SetVelocity(newVelocity);
	}

	else if (Input->GetKey(KeyCode::Down))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::Down);
		newVelocity.y += 88; //Time->GetDeltaTime() * 1.0f; // 0.5�ʸ��� ����.
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newVelocity.x = 0;
		_actor->SetVelocity(newVelocity);
	}

	if (Input->GetKeyDown(KeyCode::Space))
	{
		_actor->SetIsAttackInput(true);
	}
	if (isMoveKeyInput == false)
	{
		newVelocity = { 0,0 };
	}
	_actor->SetVelocity(newVelocity);
}
