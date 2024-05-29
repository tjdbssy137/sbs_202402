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


	if (Input->GetKey(KeyCode::Up))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::UP);
		newVelocity.x = 0;
		newVelocity.y -= 88;//Time->GetDeltaTime() * 10.0f;
		//newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
	}
	else if (Input->GetKey(KeyCode::Left))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::LEFT);
		newVelocity.x -= 88;//Time->GetDeltaTime() * 10.0f;
		//newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newVelocity.y = 0;
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::RIGHT);
		newVelocity.x += 88;//Time->GetDeltaTime() * 10.0f;
		//newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newVelocity.y = 0;
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::DOWN);
		newVelocity.y += 88;//Time->GetDeltaTime() * 10.0f;
		//newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newVelocity.x = 0;
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