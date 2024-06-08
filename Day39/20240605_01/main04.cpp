#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1. Dijikstra(BFS 진화 버전) 
//	- 설명, 구현
//	- 비용이 낮은 순으로 최선의 선택지를 계속 찾는 알고리즘
//	- 

// 2. 미로 기찾기를 무작정 길찾아보기 로직, BFS로 길찾아보기

// 3. Astar 이론

struct Vertex
{
	int Index;
};

//struct Edge
//{
//	int From;
//	int To;
//	int Cost;
//};

vector<Vertex> vertices;
vector<vector<int>> edges;

void CreateGraph()
{
	for (int i = 0; i < 6; i++)
	{
		vertices.push_back(Vertex({ i }));
	}

	// vector<int> a = vector<int>(6, -1);
	// a를 6개까지 늘리고, 모든값을 -1로 한다.
	
	// vector<vector<int>> a = vector<vector<int>>(6, vector<int>(6, -1));
	// a를 6개 사이즈로 늘리고, 그 안의 벡터들을 각각 6개 사이즈의 값을 -1로 한다.
	edges = vector<vector<int>>(6, vector<int>(6, -1));

	//from과 to 이므로 양방향 둘 다 값을 채워주어야 함.
	edges[0][1] = 30;
	edges[1][0] = 30;

	edges[0][2] = 10;
	edges[2][0] = 10;

	edges[0][5] = 100;
	edges[5][0] = 100;
	
	edges[1][2] = 2;
	edges[2][1] = 3;

	edges[1][3] = 120;
	edges[3][1] = 120;

	/*edges[2][3] = 150;
	edges[3][2] = 150;*/

	edges[2][4] = 7;
	edges[4][2] = 7;

	edges[4][5] = 1;
	edges[5][4] = 1;
	
}

struct DijikstraNode
{
	int Cost;
	int Vertex;

	bool operator<(const DijikstraNode& other) const // const 뒤에나오는 값의 수정, 변경이 불가
	{
		return Cost < other.Cost;
	}

	bool operator>(const DijikstraNode& other) const // const 뒤에나오는 값의 수정, 변경이 불가
	{
		return Cost > other.Cost;
	}

	// C#
	// 구조체 -> 스택
	// 클래스 -> 힙
};

void Dijikstra(int start)
{
	// 1. BFS 기반
	// 2. BFS -> Queue
	//	- Digikstra는 우선순위 큐(Priority Queue)
	
	// priority_queue의 특징 (트리) (값이 추가 / 삭제) (루트에 넣어두고 도장깨기를 하든/뿌리에 넣어두고 역도장깨기를하든)
	// -> 내부에서 < 연산자를 사용.
	
	// start -> end

	// start에서부터 정확히 어떤 노드를 타고가서 이 길찾기가 되었는지 파악하는 방법
	priority_queue<DijikstraNode, vector<DijikstraNode>, greater<DijikstraNode>> queue;

	// 각 인덱스로 가기위한 best 코스트
	vector<int> best(6, INT32_MAX); // 0을 넣어주면 안 됨.
	vector<int> parent(6, -1);

	// 각각 인덱스가 정점
	// 값 -> (어디서 타고 왔는지를 체크해주는)

	queue.push(DijikstraNode{ 0,0 });
	best[start] = 0;
	parent[start] = start;

	int here = start;
	while (queue.empty() == false)
	{
		DijikstraNode node = queue.top();
		queue.pop();
		
		//빙의 시작
		int cost = node.Cost;
		here = node.Vertex;

		// 더 짧은 경로를 뒤늦게 찾은 경우 스킵
		if (best[here] < cost)
		{
			continue;
		}
		cout << node.Vertex << "방문" << endl;

		for (int i = 0; i < best.size(); i++)
		{
			// 연결되어 있지 않으면 Continue
			if (edges[here][i] == -1)
			{
				continue;
			}

			//더 좋은 경로를 과거에 찾았다면 스킵
			int nextCost = best[here] + edges[here][i];
			if (best[i] <= nextCost)
			{
				continue;
			}

			// 지금까지 찾은 경로중에서 최선의 수치
			best[i] = nextCost;
			parent[i] = here;
			queue.push(DijikstraNode{ nextCost, i });
		}
	}
	cout << endl;
	for (int i = 0; i < parent.size(); i++)
	{
		cout << i << "번째 인덱스 노드는 " << parent[i] << "으로부터 오는 게 가장 빠르다" << endl;
	}
}

struct AStarNode {
	int Cost; // g(n): 시작 노드부터 현재 노드까지의 실제 비용
	int Heuristic; // h(n): 현재 노드부터 목표 노드까지의 추정 비용
	int Vertex;

	// 우선순위 큐에서 더 작은 f(n) 값을 가진 노드를 우선적으로 처리하도록 함
	bool operator>(const AStarNode& other) const {
		return (Cost + Heuristic) > (other.Cost + other.Heuristic);
	}
};

// 휴리스틱 함수 (간단한 예시로, 실제로는 목표 노드까지의 거리에 기반한 값을 반환해야 함)
int Heuristic(int current, int goal) {
	// 여기서는 간단히 절대값 차이를 반환
	return abs(goal - current);
};

void AStar(int start, int goal, const vector<vector<int>>& edges) {
	priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> queue;

	vector<int> best(edges.size(), INT_MAX);
	vector<int> parent(edges.size(), -1);

	queue.push(AStarNode{ 0, Heuristic(start, goal), start });
	best[start] = 0;
	parent[start] = start;

	while (!queue.empty()) {
		AStarNode node = queue.top();
		queue.pop();

		int here = node.Vertex;
		int cost = node.Cost;

		if (here == goal) {
			cout << "목표 노드 " << goal << " 에 도달했습니다." << endl;
			break; // 목표 노드에 도달했으면 종료
		}

		if (best[here] < cost) {
			continue; // 더 짧은 경로를 뒤늦게 찾은 경우 스킵
		}
		cout << here << "방문" << endl;

		for (int i = 0; i < edges[here].size(); i++) {
			if (edges[here][i] == -1) {
				continue; // 연결되어 있지 않으면 Continue
			}

			int nextCost = best[here] + edges[here][i];
			if (best[i] <= nextCost) {
				continue; // 더 좋은 경로를 과거에 찾았다면 스킵
			}

			best[i] = nextCost;
			parent[i] = here;
			queue.push(AStarNode{ nextCost, Heuristic(i, goal), i });
		}
	}
}

// edges 배열과 기타 필요한 세부사항은 이 코드의 범위를 벗어나므로, 
// 실제 사용 시에는 그래프의 구조와 목표 노드를 적절히 설정해야 합니다.


void main()
{
	//CreateGraph();
	//Dijikstra(0);

	vector<vector<int>> edges = {
		{-1, 4, -1, -1, -1, -1},
		{4, -1, 2, -1, -1, -1},
		{-1, 2, -1, 3, -1, -1},
		{-1, -1, 3, -1, 2, 3},
		{-1, -1, -1, 2, -1, 1},
		{-1, -1, -1, 3, 1, -1}
	};
	AStar(0, 5, edges);
}