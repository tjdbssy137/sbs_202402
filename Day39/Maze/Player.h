#pragma once

struct AStarNode
{
	int Cost; // g(n): ���� ������ ���� �������� ���� ���
	int Heuristic; // h(n): ���� ������ ��ǥ �������� ���� ���
	Vector2Int Vertex;

	// �켱���� ť���� �� ���� f(n) ���� ���� ��带 �켱������ ó���ϵ��� ��
	bool operator>(const AStarNode& other) const
	{
		return (Cost + Heuristic) > (other.Cost + other.Heuristic);
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
	void CalculatePath_Astar();

private:
	Vector2Int _pos;
	Board* _board = nullptr;
	
	vector<Vector2Int> _path;
	int _pathIndex = 0;
};

