#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAXN 100001

using namespace std;

struct Node
{
	int num;
	int weight;
};

void bfs(int start);

vector<vector<Node>> graph(MAXN);
int dist[MAXN];
bool check[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int from;
		cin >> from;
		while (true)
		{
			int to, weight;
			cin >> to;
			if (to < 0) break;

			cin >> weight;
			graph[from].push_back({ to, weight });
		}
	}

	int start = 1;
	bfs(1);
	for (int i = 2; i <= n; i++)
	{
		if (dist[start] < dist[i])
		{
			start = i;
		}
	}

	int answer = 0;
	bfs(start);
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] > answer)
		{
			answer = dist[i];
		}
	}

	cout << answer;

	return 0;
}

void bfs(int start)
{
	memset(dist, 0, sizeof(dist));
	memset(check, 0, sizeof(check));

	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			auto next = graph[cur][i].num;
			if (!check[next])
			{
				dist[next] = dist[cur] + graph[cur][i].weight;
				q.push(next);
				check[next] = true;
			}
		}
	}
}