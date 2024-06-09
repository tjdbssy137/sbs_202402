#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"
#include "TilemapScene.h"
#include <queue>
void CreatureController::SetLink(CreatureActor* actor)
{
	assert(actor != nullptr);

	_actor = actor;

}
void CreatureController::Update()
{
	_actor->SetIsAttackInput(false);

	//Udate���� �������� ���� -> Update �ֻ��� if���� �������� �񱳵� 
	// -> �ִ��� �̺�Ʈ �󵵰� ���� �������� ���� ���� ����
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
void CreatureController::Calculate_BFS()
{
	queue<Vector2Int> queue;
	_start.x = (_actor->GetPos().x - static_cast<int>(pos.x)) / tileSize;
	_start.y = (_actor->GetPos().y - static_cast<int>(pos.y)) / tileSize;
	queue.push(_start);

	int size = 100; // tile ����

	vector<vector<bool>> visited(size, vector<bool>(size, false));

	// parent[y][x] = pos (xy�� pos�� ���� �߰ߵ� ��)
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	parent[_start.y][_start.x] = _start;
	while (false == queue.empty())
	{
		Vector2Int current = queue.front();
		queue.pop();
		//�湮�ߴ� üũ
		visited[current.y][current.x] = true;

		if (current == _goal)
		{
			//�����ִ�/����.
			break;
		}

		Vector2Int dir[4] =
		{
			Vector2Int(0, -1), //Up
			Vector2Int(1, 0), // Right
			Vector2Int(0, 1), //Down
			Vector2Int(-1, 0), //Left
		};

		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = current + dir[i];
			// ���������� �� �� �ִ� �����̸�,
			if (_goal != Vector2Int{ -1, -1 } && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos�� curren�κ��� �Խ��ϴ�.
				parent[nextPos.y][nextPos.x] = current;
				queue.push(nextPos);
			}
		}
	}
	// ��ǥ�� �����ؼ�
	// ĳ���� �̵�
}