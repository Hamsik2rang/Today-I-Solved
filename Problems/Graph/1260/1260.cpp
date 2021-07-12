#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];

void DFS(int x)
{
	static bool check[1001]{ false };
	check[x] = true;
	cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++)
	{
		int next = graph[x][i];
		if (!check[next])
		{
			DFS(next);
		}
	}
}

void BFS(int x)
{
	static bool check[1001]{ false };
	queue<int> q;
	check[x] = true;
	q.push(x);
	cout << x << ' ';
	while (!q.empty())
	{
		int cur = q.front();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (!check[next])
			{
				check[next] = true;
				cout << next << ' ';
				q.push(next);
			}
		}
		q.pop();
	}
}

int main()
{
	int v, e, start;
	cin >> v >> e >> start;

	for (int i = 0; i < e; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 0; i < v; i++)
	{
		sort(graph[i].begin(), graph[i].end(), less<int>());
	}

	DFS(start);
	cout << endl;
	BFS(start);

	return 0;
}