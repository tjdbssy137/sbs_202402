#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"
#include "TilemapScene.h"

void CreatureController::SetLink(CreatureActor* actor)
{
	assert(actor != nullptr);

	_actor = actor;
}
void CreatureController::Update()
{
	_actor->SetIsAttackInput(false);

	//Udate문은 매프레임 들어옴 -> Update 최상위 if문은 매프레임 비교됨 
	// -> 최대한 이벤트 빈도가 적은 내용으로 적는 것이 좋음
	if (Input->GetKey(KeyCode::Up))
	{
		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.y -= 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
			}
			_actor->ChangeDirection(eCreatureDirection::UP);
		}
	}
	else if (Input->GetKey(KeyCode::Left))
	{
		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.x -= 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
			}
			_actor->ChangeDirection(eCreatureDirection::LEFT);
		}
	}
	else if (Input->GetKey(KeyCode::Right))
	{
		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.x += 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
			}
			_actor->ChangeDirection(eCreatureDirection::RIGHT);
		}
	}
	else if (Input->GetKey(KeyCode::Down))
	{
		if (_actor->CanMove())
		{
			Vector2Int cellPos = _actor->GetCellPos();
			cellPos.y += 1;

			TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
			assert(scene != nullptr);
			if (scene == nullptr)
			{
				return;
			}

			if (scene->CanGo(_actor, cellPos))
			{
				_actor->SetCellPos(cellPos);
				_actor->SetState(CreatureState::Move);
			}
			_actor->ChangeDirection(eCreatureDirection::DOWN);
		}
	}

	if (Input->GetKeyDown(KeyCode::Space))
	{
		_actor->SetIsAttackInput(true);
	}

}