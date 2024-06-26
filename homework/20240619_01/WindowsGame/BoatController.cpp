#include "pch.h"
#include "BoatController.h"
#include "BoatActor.h"
#include "TilemapScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "MapToolController.h"
#include "Dev2Scene.h"
#include <queue>

void BoatController::SetLink(BoatActor* actor)
{
	assert(actor != nullptr);

	_actor = actor;

}
void BoatController::Update()
{
	//Udate���� �������� ���� -> Update �ֻ��� if���� �������� �񱳵� 
	// -> �ִ��� �̺�Ʈ �󵵰� ���� �������� ���� ���� ����

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

	// parent[y][x] = pos (xy�� pos�� ���� �߰ߵ� ��)
	vector<vector<Vector2Int>> parent(mapSize.y, vector<Vector2Int>(mapSize.x, Vector2Int(-1, -1)));

	parent[startPos.y][startPos.x] = startPos;
	while (false == queue.empty())
	{
		PQNode current = queue.top();
		queue.pop();
		//�湮�ߴ� üũ

		visited[current.Vertex.y][current.Vertex.x] = true;

		if (current.Vertex == endPos)
		{
			//�����ִ�/����.
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
			// ���������� �� �� �ִ� �����̸�,
			if (scene->CanGo(_actor, nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos�� curren�κ��� �Խ��ϴ�.
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i];
				newNode.Cost = newNode.G + (dest - nextPos).Length();
				parent[nextPos.y][nextPos.x] = current.Vertex; // parent�� ��θ� ������.
				queue.push(newNode);
			}
		}
	}
	//parent�� 2���� ���Ϳ��� 1���� ���ͷ� ��ȯ�� �ʿ���
	// ���Ϳ� �ݴ� �������� �ֱ� ������ ���͸� ���������.
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

	// ���� ������
	for (int i = 0; i < path.size() / 2; i++) 	// �迭�� ����
	{
		// ����
		Vector2Int temp = path[i];
		path[i] = path[path.size() - 1 - i];
		path[path.size() - 1 - i] = temp;
	}
	result = path;
	return result;
}