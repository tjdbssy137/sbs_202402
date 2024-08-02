#include "pch.h"
#include "BoatController.h"
#include "BoatActor.h"
#include "TowerDefenseScene.h"
#include "Tilemap.h"
#include "TilemapActor.h"
#include "MapToolController.h"
#include <queue>
#include "GameWave.h"
#include "EffectActor.h"

void BoatController::SetLink(BoatActor* boat)
{
	assert(boat != nullptr);

	_boat = boat;

	// Effect
	_effect = new EffectActor();
	_effect->Init();
	CurrentScene->SpawnActor(_effect);
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
	case BoatState::Goal:
		this->FinishedBoatState();
		break;
	case BoatState::Die:
		this->DeathEffect();
		break;
	case BoatState::None:
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

	vector<Vector2Int> path = Calculator_Astar(STARTPOS, DESTPOS);

	_boat->SetPath(path);
	_boat->SetState(BoatState::Move);
}

void BoatController::Arrive()
{
	if (_boat->GetCellPos() == DESTPOS)
	{
		//cout << "����" << endl;
		UserDatas->AddEnterEnemyCount();
		_boat->SetState(BoatState::Goal);
		// �������� �����ϸ� �� ������ ��ġ�� �ٽ� ���� �������� �缳��.
	}
}

void BoatController::FinishedBoatState()
{
	_boat->SetCellPos({ 54, 25 }, true);

	GameEvent<BoatActor*>* gameEvent = Events->GetEvent<BoatActor*>("PushBoatActor");
	gameEvent->Invoke(_boat);

	// state ����
	_boat->SetState(BoatState::None);
}

void BoatController::DeathEffect()
{
	_effect->SetPos(_boat->GetPos());
	_effect->OnEffect(0.6f);

	_boat->SetCellPos({ 54, 25 }, true);
	GameEvent<BoatActor*>* gameEvent = Events->GetEvent<BoatActor*>("PushBoatActor");
	gameEvent->Invoke(_boat);

	UserDatas->MakeGold(_boat->GetBoatData().Gold);

	_boat->SetState(BoatState::None);
}

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
			if (scene->CanGo(nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos�� curren�κ��� �Խ��ϴ�.
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i];
				newNode.Cost = newNode.G + (dest - nextPos).Length();
				// 
				if (newNode.Cost < best[nextPos.y][nextPos.x])
				{
					parent[nextPos.y][nextPos.x] = current.Vertex; // parent�� ��θ� ������.
					best[nextPos.y][nextPos.x] = newNode.Cost;
				}
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