#pragma once

struct AStarNode
{
	int Cost; // g(n): ���� ������ ���� �������� ���� ���
	int Heuristic; // h(n): ���� ������ ��ǥ �������� ���� ���
	Vector2Int Vertex;

	bool operator>(const AStarNode& other) const
	{
		return (Cost + Heuristic) > (other.Cost + other.Heuristic);
	}
};

struct DijikstraNode
{
	int Cost;
	Vector2Int Vertex;

	bool operator<(const DijikstraNode& other) const // const �ڿ������� ���� ����, ������ �Ұ�
	{
		return Cost < other.Cost;
	}

	bool operator>(const DijikstraNode& other) const // const �ڿ������� ���� ����, ������ �Ұ�
	{
		return Cost > other.Cost;
	}
};

class Board;
class Player
{
public:
	void Init(Board* board);
	void Update();
	void SetPos(Vector2Int pos) { _pos = pos; }
	Vector2Int GetPos() { return _pos; }

	bool CanGo(Vector2Int pos);
	void CalculatePath_RightHand();
	void CalculatePath_BFS();
	void CalculatePath_MY_Astar();
	void CalculatePath_Astar();
	void CalculatePath_Dijikstra();
private:
	Vector2Int _pos;
	Board* _board = nullptr;
	
	vector<Vector2Int> _path;
	int _pathIndex = 0;
};

