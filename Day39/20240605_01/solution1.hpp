#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//DFS, BFS
// �����ڵ�

void dfs_recursive(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    visited[start] = 1;
    //1. start���� �����ִ� ������ üũ
    for (int i = 0; i < n; i++)
    {
        if (computers[start][i] == 1 && visited[i] == 0)
        {
            dfs_recursive(n, computers, i, visited);
        }
    }
}


void dfs_stack(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    stack<int> s;
    s.push(start);
    while (false == s.empty())
    {
        int current = s.top();
        s.pop();
        //�湮�ߴ� üũ
        visited[current] = 1;

        //1. current���� �����ִ� ������ üũ
        for (int i = 0; i < n; i++)
        {
            if (computers[current][i] == 1 && visited[i] == 0)
            {
                s.push(i);
            }
        }

    }
}

void bfs_stack(int n, vector<vector<int>> computers, int start, vector<int>& visited)
{
    queue<int> s;
    s.push(start);
    while (false == s.empty())
    {
        int current = s.front();
        s.pop();
        //�湮�ߴ� üũ
        visited[current] = 1;

        //1. current���� �����ִ� ������ üũ
        for (int i = 0; i < n; i++)
        {
            if (computers[current][i] == 1 && visited[i] == 0)
            {
                s.push(i);
            }
        }

    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    //dfs�� Ȱ���ؼ� 
    //�� �������� ������ �ȵǾ������� ������ ã�Բ�.

    /*vector<int> visited = {};
    for (int i = 0; i < n; i++)
    {
        visited.push_back(0);
    }*/
    vector<int> visited(n, 0);  // 1 1 0 

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            ::bfs_stack(n, computers, i, visited);
            answer++;
        }
    }


    return answer;
}