#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"
#include "Dev2Scene.h"
void CreatureController::SetLink(CreatureActor* actor)
{
	assert(actor != nullptr);

	_actor = actor;

	_currentScene = dynamic_cast<Dev2Scene*>(GET_SINGLE(SceneManager)->GetCurrentScene());
}
void CreatureController::Update()
{
	_actor->SetIsAttackInput(false);
	Vector2 newVelocity = _actor->GetVelocity(); // �̵������� �Ǵ�, ��� isMoveKeyInput�� ���⸸ �ص� �ɵ�
	bool isMoveKeyInput = false;

	Vector2 newPos = _actor->GetPos(); // �̵� ��ġ �� ����
	int tileSize = _currentScene->GetTileSize();
	if (Input->GetKey(KeyCode::Up))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::UP);
		newVelocity.y -= Time->GetDeltaTime() * 10.0f;
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newPos.y -= tileSize;
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::DOWN);
		newVelocity.y += Time->GetDeltaTime() * 10.0f;
		newVelocity.y = clamp(newVelocity.y, -1.0f, 1.0f);
		newPos.y += tileSize;
	}
	else if (Input->GetKey(KeyCode::Left))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::LEFT);
		newVelocity.x -= Time->GetDeltaTime() * 10.0f;
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newPos.x -= tileSize;
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		isMoveKeyInput = true;
		_actor->ChangeDirection(eCreatureDirection::RIGHT);
		newVelocity.x += Time->GetDeltaTime() * 10.0f;
		newVelocity.x = clamp(newVelocity.x, -1.0f, 1.0f);
		newPos.x += tileSize;
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

	if (isMoveKeyInput == true) // �̵����Ͻÿ���
	{
		_trueTime -= Time->GetDeltaTime();
		if (_trueTime <= 0) // 0.135�ʶ�� �����̸� ����
		{
			_actor->SetVelocity(newVelocity); // �̵��� �ϸ�
			_actor->SetDirNewPos(newPos); // �̵� ������ �̷��ϴ�
			_trueTime = 0.135f;
		}
	}
}