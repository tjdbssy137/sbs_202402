#pragma once

struct AStarNode
{
	int Cost; // g(n): 시작 노드부터 현재 노드까지의 실제 비용
	int Heuristic; // h(n): 현재 노드부터 목표 노드까지의 추정 비용
	Vector2Int Vertex;

	// 우선순위 큐에서 더 작은 f(n) 값을 가진 노드를 우선적으로 처리하도록 함
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

