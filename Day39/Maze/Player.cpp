#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <queue>
void Player::Init(Board* board)
{
	_board = board;

	_pos = _board->GetEnterPos();

	//this->CalculatePath_RightHand();
	this->CalculatePath_BFS();
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

void Player::CalculatePath_Astar()
{
	Vector2Int start = _board->GetEnterPos();
	Vector2Int goal = _board->GetExitPos();

	priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> queue;

	int size = _board->GetSize();
	vector<vector<int>> best(size, vector<int>(size, INT_MAX));
	vector<vector<Vector2Int>> parent(size, vector<Vector2Int>(size, Vector2Int(-1, -1)));

	//vector<Vector2Int> best(_board->GetSize(), Vector2Int(-1, -1)); // vector<Vector2Int> best(_path.size(), INT_MAX);
	//vector<Vector2Int> parent(_board->GetSize(), Vector2Int(-1, -1)); // vector<Vector2Int> parent(_path.size(), -1);

	int Heuristic = (abs(start.y - goal.y) + abs(start.x - goal.x)) * 10;
	queue.push(AStarNode{ 0, Heuristic, start });
	best[start.y][start.x] = 0;
	parent[start.y][start.x] = start;

	Vector2Int current = start;
	while (false == queue.empty())
	{
		AStarNode node = queue.top();
		queue.pop();
		//�湮�ߴ� 

		int cost = node.Cost;
		current = node.Vertex;
		int H = (abs(current.y - goal.y) + abs(current.x - goal.x)) * 10;

		best[current.y][current.x] = 0;

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
			if (this->CanGo(nextPos) && best[nextPos.y][nextPos.x] == 0)
			{
				// nextPos�� curren�κ��� �Խ��ϴ�.
				parent[nextPos.y][nextPos.x] = current;
				queue.push(AStarNode{ i, , nextPos});
			}
		}
	}
}