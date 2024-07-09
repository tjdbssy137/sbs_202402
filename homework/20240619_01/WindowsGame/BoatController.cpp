#include "pch.h"
#include "BoatController.h"
#include "BoatActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "MapToolController.h"
#include "Dev2Scene.h"
#include <queue>

void BoatController::SetLink(BoatActor* boat)
{
	assert(boat != nullptr);

	_boat = boat;

}
void BoatController::Update()
{
	switch (_boat->GetState())
	{
	case BoatState::Start:
		this->Depart();
		break;
	case BoatState::Move:
		this->Arrive();
		break;
	default:
		break;
	}
}

void BoatController::Depart()
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

	vector<Vector2Int> path = Calculator_Astar(_boat->GetCellPos(),
		tilemapActor->GetTileIndexByPos({ 5 * 32, 3 * 32 }));

	_boat->SetPath(path);
	_boat->SetState(BoatState::Move);
}

void BoatController::Arrive()
{
	if (_boat->GetCellPos() == Vector2Int{ 5, 3 })
	{
		cout << "도착" << endl;
		_boat->SetState(BoatState::Goal);
		// 목적지에 도착하면 이 액터의 위치를 다시 시작 지점으로 재설정.
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


vector<Vector2Int> BoatController::Calculator_Astar(Vector2Int startPos, Vector2Int endPos)
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
	vector<vector<float>> best(mapSize.y, vector<float>(mapSize.x, 999999));

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
			Vector2Int(-1, 0) //Left

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
			if (scene->CanGo(_boat, nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos는 curren로부터 왔습니다.
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i];
				newNode.Cost = newNode.G + (dest - nextPos).Length();
				// 
				if (newNode.Cost < best[nextPos.y][nextPos.x])
				{
					parent[nextPos.y][nextPos.x] = current.Vertex; // parent는 경로를 연결함.
					best[nextPos.y][nextPos.x] = newNode.Cost;
				}
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