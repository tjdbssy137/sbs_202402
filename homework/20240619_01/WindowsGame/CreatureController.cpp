#include "pch.h"
#include "CreatureController.h"
#include "CreatureActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "MapToolController.h"
#include "Dev2Scene.h"
#include <queue>

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

	if (Input->GetKeyDown(KeyCode::RightMouse))
	{
		
		TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
		assert(scene != nullptr);
		if (scene == nullptr)
		{
			return;
		}
		TilemapActor* tilemapActor = scene->GetTilemapActor();
		assert(tilemapActor != nullptr);
		if (tilemapActor == nullptr)
		{
			return;
		}

		vector<Vector2Int> path = Calculator_Astar(_actor->GetCellPos(), 
			tilemapActor->GetTileIndexByPos(Input->GetMousePos()));
		_actor->SetPath(path);
	}

}
struct AstarNode
{
	int Cost;
	Vector2Int Vertex;
	int G;

	bool operator<(const AstarNode& other)const
	{
		return Cost < other.Cost;
	}

	bool operator>(const AstarNode& other)const
	{
		return Cost > other.Cost;
	}
};


vector<Vector2Int> CreatureController::Calculator_Astar(Vector2Int startPos, Vector2Int endPos)
{
	vector<Vector2Int> result;
	TilemapScene* scene = dynamic_cast<TilemapScene*>(CurrentScene);
	assert(scene != nullptr);
	if (scene == nullptr)
	{
		return result;
	}

	Tilemap* tilemap = scene->GetTilemap();
	assert(tilemap != nullptr);
	if (tilemap == nullptr)
	{
		return result;
	}
	
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> queue;

	Vector2Int dest = endPos;
	PQNode node;
	node.Vertex = startPos;
	node.G = 0;
	node.Cost = node.G + (dest - startPos).Length();
	queue.push(node);

	Vector2Int mapSize = tilemap->GetMapSize();
	vector<vector<bool>> visited(mapSize.y, vector<bool>(mapSize.x, false));

	// parent[y][x] = pos (xy는 pos에 의해 발견된 곳)
	vector<vector<Vector2Int>> parent(mapSize.y, vector<Vector2Int>(mapSize.x, Vector2Int(-1, -1)));

	parent[startPos.y][startPos.x] = startPos;
	while (false == queue.empty())
	{
		PQNode current = queue.top();
		queue.pop();
		//방문했다 체크

		visited[current.Vertex.y][current.Vertex.x] = true;

		if (current.Vertex == endPos)
		{
			//갈수있다/없다.
			break;
		}

		Vector2Int dir[4] =
		{
			Vector2Int(0, -1), //Up
			Vector2Int(1, 0), // Right
			Vector2Int(0, 1), //Down
			Vector2Int(-1, 0), //Left
		};

		int moveCost[4] =
		{
			1,
			1,
			1,
			1
		};
		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = current.Vertex + dir[i];
			// 다음지점이 갈 수 있는 지점이면,
			if (scene->CanGo(_actor, nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos는 curren로부터 왔습니다.
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i]; 
				newNode.Cost = newNode.G + (dest - nextPos).Length(); 
				parent[nextPos.y][nextPos.x] = current.Vertex; // parent는 경로를 연결함.
				queue.push(newNode);
			}
		}
	}
	//parent는 2차원 벡터여서 1차원 벡터로 전환이 필요함
	// 벡터에 반대 방향으로 넣기 때문에 벡터를 뒤집어야함.
	Vector2Int pos = endPos;
	vector<Vector2Int> path = {};
	while (true)
	{
		path.push_back(pos);
		if (pos == startPos)
		{
			break;
		}
		pos = parent[pos.y][pos.x];
	}

	// 백터 뒤집기
	for (int i = 0; i < path.size() / 2; i++) 	// 배열의 절반
	{
		// 스왑
		Vector2Int temp = path[i];
		path[i] = path[path.size() - 1 - i];
		path[path.size() - 1 - i] = temp;
	}
	result = path;
	return result;
}