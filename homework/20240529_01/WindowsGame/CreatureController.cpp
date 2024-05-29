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
	Vector2 newVelocity = _actor->GetVelocity(); // 이동중임을 판단, 사실 isMoveKeyInput을 쓰기만 해도 될듯
	bool isMoveKeyInput = false;

	Vector2 newPos = _actor->GetPos(); // 이동 위치 및 방향


	if (Input->GetKey(KeyCode::Up))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::UP);
		newVelocity.y -= Time->GetDeltaTime() * 10.0f;
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newPos.y -= 88;
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::DOWN);
		newVelocity.y += Time->GetDeltaTime() * 10.0f;
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newPos.y += 88;
	}
	else if (Input->GetKey(KeyCode::Left))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::LEFT);
		newVelocity.x -= Time->GetDeltaTime() * 10.0f;
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newPos.x -= 88;
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::RIGHT);
		newVelocity.x += Time->GetDeltaTime() * 10.0f;
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newPos.x += 88;
	}


	if (Input->GetKeyDown(KeyCode::Space))
	{
		_actor->SetIsAttackInput(true);
	}

	if (isMoveKeyInput == false)
	{
		newVelocity = { 0, 0 };
		_actor->SetVelocity(newVelocity);
	}

	if (isMoveKeyInput == true) // 이동중일시에만
	{
		_trueTime -= Time->GetDeltaTime();
		if (_trueTime <= 0) // 0.135초라는 딜레이를 갖고
		{
			_actor->SetVelocity(newVelocity); // 이동을 하며
			_actor->SetDirNewPos(newPos); // 이동 방향은 이러하다
			_trueTime = 0.135f;
		}
	}
}