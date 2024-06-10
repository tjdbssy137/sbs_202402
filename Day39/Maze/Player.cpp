#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <queue>
void Player::Init(Board* board)
{
	_board = board;

	_pos = _board->GetEnterPos();

	//this->CalculatePath_RightHand();
	//this->CalculatePath_BFS();
	//this->CalculatePath_Dijikstra();
	this->CalculatePath_Astar(); 
}

void Player::Update()
{
	if (_path.size() <= _pathIndex)
	{
		return;
	}
	_pos = _path[_pathIndex];
	_pathIndex++;
}

bool Player::CanGo(Vector2Int pos)
{
	//�����ִ���������üũ

	return _board->CanGo(pos);
}
void Player::CalculatePath_RightHand()
{
	// _path�� ���� ���� �Լ�
	// _path.push_back();

	Vector2Int pos = _pos;

	_path.clear();
	_path.push_back(pos);

	Vector2Int dest = _board->GetExitPos();
	
	Vector2Int dir[4] =
	{
		Vector2Int(0, -1), //Up
		Vector2Int(1, 0), // Right
		Vector2Int(0, 1), //Down
		Vector2Int(-1, 0), //Left
	};

	//Ż�ⱸ�� ã�� ������ ���ѷ���, ��� ������ �������� �̵�
	int index = 0;
	int dirIndex = 0;
	while (pos != dest)
	{
		index++;
		if (index > 10000)
		{
			return;
		}
		int newDir = dirIndex + 1;
		+ 1;
		newDir %= 4;
		
		// ������ �������� �� �� ������
		if (CanGo(pos + dir[newDir]))
		{
			dirIndex = newDir;
			pos += dir[newDir];
			_path.push_back(pos);
		}
		// ���������� �� ���µ� �����δ� �� �� ������
		else if (CanGo(pos + dir[dirIndex]))
		{
			pos += dir[dirIndex];
			_path.push_back(pos);
		}
		else
		{
			//���� �������� 90�� ȸ��
			dirIndex = (dirIndex + 3) % 4;
		}
	}
}

void Player::CalculatePath_BFS()
{
	queue<Vector2Int> queue;
	queue.push(_pos);

	int size = _board->GetSize();
	vector<vector<bool>> visited(size, vector<bool>(size, false));

	// parent[y][x] = pos (xy�� pos�� ���� �߰ߵ� ��)
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	parent[_pos.y][_pos.x] = _pos;
	while (false == queue.empty())
	{
		Vector2Int current = queue.front();
		queue.pop();
		//�湮�ߴ� üũ
		visited[current.y][current.x] = true;

		if (current == _board->GetExitPos())
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
			if (this->CanGo(nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos�� curren�κ��� �Խ��ϴ�.
				parent[nextPos.y][nextPos.x] = current;
				queue.push(nextPos);
			}
		}
	}

	//_path�� ��ƺ���
	// --> ���������� ������ ������ �ȴ�.

	Vector2Int pos = _board->GetExitPos();
	while (true)
	{
		_path.push_back(pos);
		if (pos == _board->GetEnterPos())
		{
			break;
		}
		pos = parent[pos.y][pos.x];
	}

	// ���� ������
	for (int i = 0; i < _path.size() / 2; i++) 	// �迭�� ����
	{
		// ����
		Vector2Int temp = _path[i];
		_path[i] = _path[_path.size() - 1 - i];
		_path[_path.size() - 1 - i] = temp;
	}
}

void Player::CalculatePath_Dijikstra()
{
	Vector2Int start = _pos;
	priority_queue<DijikstraNode, vector<DijikstraNode>, greater<DijikstraNode>> queue;

	int size = _board->GetSize();
	// �� �ε����� �������� best �ڽ�Ʈ
	vector<vector<int>> best(size, vector<int>(size, INT_MAX)); // 0�� �־��ָ� �� ��.
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));
	
	queue.push(DijikstraNode{0, start});
	best[start.y][start.x] = 0;
	parent[start.y][start.x] = start;

	Vector2Int here = start;
	while (false == queue.empty())
	{
		DijikstraNode node = queue.top();
		queue.pop();

		//���� ����
		int cost = node.Cost;
		here = node.Vertex;

		if (here == _board->GetExitPos())
		{
			//�����ִ�/����.
			break;
		}

		if (best[here.y][here.x] < cost)
		{
			continue;
		}
		
		// �� ����(��, ��, ��, ��)���� �̵�
		Vector2Int dir[4] =
		{
			Vector2Int(0, -1), //Up
			Vector2Int(1, 0), // Right
			Vector2Int(0, 1), //Down
			Vector2Int(-1, 0), //Left
		};

		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = here + dir[i];
			
			// ����Ǿ� ���� ������ Continue
			if (nextPos == Vector2Int{ -1, -1 })
			{
				continue;
			}
			if (this->CanGo(nextPos))
			{
				//�� ���� ��θ� ���ſ� ã�Ҵٸ� ��ŵ
				int nextCost = best[here.y][here.x] + 100;
				if (best[nextPos.y][nextPos.x] <= nextCost)
				{
					continue;
				}
				// ���ݱ��� ã�� ����߿��� �ּ��� ��ġ
				best[nextPos.y][nextPos.x] = nextCost;
				parent[nextPos.y][nextPos.x] = here;
				queue.push(DijikstraNode{nextCost, nextPos});
			}
		}
	}
	
	//_path�� ��ƺ���
	// --> ���������� ������ ������ �ȴ�.

	Vector2Int pos = _board->GetExitPos();
	while (true)
	{
		_path.push_back(pos);
		if (pos == _board->GetEnterPos())
		{
			break;
		}
		pos = parent[pos.y][pos.x];
	}

	// ���� ������
	for (int i = 0; i < _path.size() / 2; i++) 	// �迭�� ����
	{
		// ����
		Vector2Int temp = _path[i];
		_path[i] = _path[_path.size() - 1 - i];
		_path[_path.size() - 1 - i] = temp;
	}
}

void Player::CalculatePath_MY_Astar()
{
	Vector2Int start = _pos;
	Vector2Int goal = _board->GetExitPos();

	priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> queue;

	int size = _board->GetSize();

	vector<vector<int>> best(size, vector<int>(size, INT_MAX));
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	int heuristic = (abs(start.y - goal.y) + abs(start.x - goal.x)) * 10;
	queue.push(AStarNode{0, heuristic, start});
	best[start.y][start.x] = 0;
	parent[start.y][start.x] = start;

	Vector2Int here = start;
	while (!queue.empty())
	{
		AStarNode node = queue.top();
		queue.pop();
		//�湮�ߴ� 

		int cost = node.Cost;
		here = node.Vertex;

		if (here == goal)
		{
			break;
		}

		if (best[here.y][here.x] < cost)
		{
			continue;
		}

		// �� ����(��, ��, ��, ��)���� �̵�
		Vector2Int dir[4] =
		{
			Vector2Int(0, -1), //Up
			Vector2Int(1, 0), // Right
			Vector2Int(0, 1), //Down
			Vector2Int(-1, 0), //Left
		};

		for (int i = 0; i < 4; i++)
		{
			Vector2Int nextPos = here + dir[i];
			if (this->CanGo(nextPos)) // �����ִ°�������
			{
				int nextCost = best[here.y][here.x] + 10;
				// �� ���� ��θ� ���ſ� ã�Ҵٸ� ��ŵ
				if (best[nextPos.y][nextPos.x] <= nextCost)
				{
					continue;
				}

				best[nextPos.y][nextPos.x] = nextCost;
				parent[nextPos.y][nextPos.x] = here;
				int heuristic = (abs(nextPos.y - goal.y) + abs(nextPos.x - goal.x)) * 10;
				queue.push(AStarNode{ nextCost, heuristic, nextPos });
			}
		}
	}
	//_path�� ��ƺ���
	// --> ���������� ������ ������ �ȴ�.
	Vector2Int pos = _board->GetExitPos();
	while (true)
	{
		_path.push_back(pos);
		if (pos == _board->GetEnterPos())
		{
			break;
		}
		pos = parent[pos.y][pos.x];
	}

	// ���� ������
	for (int i = 0; i < _path.size() / 2; i++) 	// �迭�� ����
	{
		// ����
		Vector2Int temp = _path[i];
		_path[i] = _path[_path.size() - 1 - i];
		_path[_path.size() - 1 - i] = temp;
	}
}


struct PQNode
{
	int Cost;
	Vector2Int Vertex;

	int G;

	bool operator<(const PQNode& other) const
	{
		return Cost < other.Cost;
	}
	bool operator>(const PQNode& other) const
	{
		return Cost > other.Cost;
	}
};

void Player::CalculatePath_Astar() // �������� §��
{
	// less �� ū�� ��Ʈ�� ��
	// greater �� ������ �� ��Ʈ�� ��
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> queue;
	
	Vector2Int dest = _board->GetExitPos();
	PQNode node;
	node.Vertex = _pos;
	node.G = 0;
	node.Cost = node.G + (dest - _pos).Length();
	queue.push(node);

	int size = _board->GetSize();
	vector<vector<bool>> visited(size, vector<bool>(size, false));

	// parent[y][x] = pos (xy�� pos�� ���� �߰ߵ� ��)
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	parent[_pos.y][_pos.x] = _pos;
	while (false == queue.empty())
	{
		PQNode current = queue.top();
		queue.pop();
		//�湮�ߴ� üũ
		visited[current.Vertex.y][current.Vertex.x] = true;

		if (current.Vertex == _board->GetExitPos())
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
			if (this->CanGo(nextPos) && visited[nextPos.y][nextPos.x] == 0)
			{
				// nextPos�� curren�κ��� �Խ��ϴ�.
				parent[nextPos.y][nextPos.x] = current.Vertex;
				PQNode newNode;
				newNode.Vertex = nextPos;
				newNode.G = current.G + moveCost[i];
				newNode.Cost = newNode.G + (dest - _pos).Length();
				queue.push(newNode);
			}
		}
	}

	//_path�� ��ƺ���
	// --> ���������� ������ ������ �ȴ�.

	Vector2Int pos = _board->GetExitPos();
	while (true)
	{
		_path.push_back(pos);
		if (pos == _board->GetEnterPos())
		{
			break;
		}
		pos = parent[pos.y][pos.x];
	}

	// ���� ������
	for (int i = 0; i < _path.size() / 2; i++) 	// �迭�� ����
	{
		// ����
		Vector2Int temp = _path[i];
		_path[i] = _path[_path.size() - 1 - i];
		_path[_path.size() - 1 - i] = temp;
	}
}