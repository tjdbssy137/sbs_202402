#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 1. Dijikstra(BFS ��ȭ ����) 
//	- ����, ����
//	- ����� ���� ������ �ּ��� �������� ��� ã�� �˰���
//	- 

// 2. �̷� ��ã�⸦ ������ ��ã�ƺ��� ����, BFS�� ��ã�ƺ���

// 3. Astar �̷�

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
	// a�� 6������ �ø���, ��簪�� -1�� �Ѵ�.
	
	// vector<vector<int>> a = vector<vector<int>>(6, vector<int>(6, -1));
	// a�� 6�� ������� �ø���, �� ���� ���͵��� ���� 6�� �������� ���� -1�� �Ѵ�.
	edges = vector<vector<int>>(6, vector<int>(6, -1));

	//from�� to �̹Ƿ� ����� �� �� ���� ä���־�� ��.
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

	bool operator<(const DijikstraNode& other) const // const �ڿ������� ���� ����, ������ �Ұ�
	{
		return Cost < other.Cost;
	}

	bool operator>(const DijikstraNode& other) const // const �ڿ������� ���� ����, ������ �Ұ�
	{
		return Cost > other.Cost;
	}

	// C#
	// ����ü -> ����
	// Ŭ���� -> ��
};

void Dijikstra(int start)
{
	// 1. BFS ���
	// 2. BFS -> Queue
	//	- Digikstra�� �켱���� ť(Priority Queue)
	
	// priority_queue�� Ư¡ (Ʈ��) (���� �߰� / ����) (��Ʈ�� �־�ΰ� ������⸦ �ϵ�/�Ѹ��� �־�ΰ� ��������⸦�ϵ�)
	// -> ���ο��� < �����ڸ� ���.
	
	// start -> end

	// start�������� ��Ȯ�� � ��带 Ÿ���� �� ��ã�Ⱑ �Ǿ����� �ľ��ϴ� ���
	priority_queue<DijikstraNode, vector<DijikstraNode>, greater<DijikstraNode>> queue;

	// �� �ε����� �������� best �ڽ�Ʈ
	vector<int> best(6, INT32_MAX); // 0�� �־��ָ� �� ��.
	vector<int> parent(6, -1);

	// ���� �ε����� ����
	// �� -> (��� Ÿ�� �Դ����� üũ���ִ�)

	queue.push(DijikstraNode{ 0,0 });
	best[start] = 0;
	parent[start] = start;

	int here = start;
	while (queue.empty() == false)
	{
		DijikstraNode node = queue.top();
		queue.pop();
		
		//���� ����
		int cost = node.Cost;
		here = node.Vertex;

		// �� ª�� ��θ� �ڴʰ� ã�� ��� ��ŵ
		if (best[here] < cost)
		{
			continue;
		}
		cout << node.Vertex << "�湮" << endl;

		for (int i = 0; i < best.size(); i++)
		{
			// ����Ǿ� ���� ������ Continue
			if (edges[here][i] == -1)
			{
				continue;
			}

			//�� ���� ��θ� ���ſ� ã�Ҵٸ� ��ŵ
			int nextCost = best[here] + edges[here][i];
			if (best[i] <= nextCost)
			{
				continue;
			}

			// ���ݱ��� ã�� ����߿��� �ּ��� ��ġ
			best[i] = nextCost;
			parent[i] = here;
			queue.push(DijikstraNode{ nextCost, i });
		}
	}
	cout << endl;
	for (int i = 0; i < parent.size(); i++)
	{
		cout << i << "��° �ε��� ���� " << parent[i] << "���κ��� ���� �� ���� ������" << endl;
	}
}

struct AStarNode {
	int Cost; // g(n): ���� ������ ���� �������� ���� ���
	int Heuristic; // h(n): ���� ������ ��ǥ �������� ���� ���
	int Vertex;

	// �켱���� ť���� �� ���� f(n) ���� ���� ��带 �켱������ ó���ϵ��� ��
	bool operator>(const AStarNode& other) const {
		return (Cost + Heuristic) > (other.Cost + other.Heuristic);
	}
};

// �޸���ƽ �Լ� (������ ���÷�, �����δ� ��ǥ �������� �Ÿ��� ����� ���� ��ȯ�ؾ� ��)
int Heuristic(int current, int goal) {
	// ���⼭�� ������ ���밪 ���̸� ��ȯ
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
			cout << "��ǥ ��� " << goal << " �� �����߽��ϴ�." << endl;
			break; // ��ǥ ��忡 ���������� ����
		}

		if (best[here] < cost) {
			continue; // �� ª�� ��θ� �ڴʰ� ã�� ��� ��ŵ
		}
		cout << here << "�湮" << endl;

		for (int i = 0; i < edges[here].size(); i++) {
			if (edges[here][i] == -1) {
				continue; // ����Ǿ� ���� ������ Continue
			}

			int nextCost = best[here] + edges[here][i];
			if (best[i] <= nextCost) {
				continue; // �� ���� ��θ� ���ſ� ã�Ҵٸ� ��ŵ
			}

			best[i] = nextCost;
			parent[i] = here;
			queue.push(AStarNode{ nextCost, Heuristic(i, goal), i });
		}
	}
}

// edges �迭�� ��Ÿ �ʿ��� ���λ����� �� �ڵ��� ������ ����Ƿ�, 
// ���� ��� �ÿ��� �׷����� ������ ��ǥ ��带 ������ �����ؾ� �մϴ�.


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