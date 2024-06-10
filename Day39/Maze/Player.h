#pragma once

struct AStarNode
{
	int Cost; // g(n): 시작 노드부터 현재 노드까지의 실제 비용
	int Heuristic; // h(n): 현재 노드부터 목표 노드까지의 추정 비용
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

	bool operator<(const DijikstraNode& other) const // const 뒤에나오는 값의 수정, 변경이 불가
	{
		return Cost < other.Cost;
	}

	bool operator>(const DijikstraNode& other) const // const 뒤에나오는 값의 수정, 변경이 불가
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

