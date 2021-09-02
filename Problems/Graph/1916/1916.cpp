// Simple solution.
// get input, and find minimum cost using dijkstra.

#define _CRT_SECURE_NO_WARNINGS
#define MAXN (1001)
#define INF (0x7FFFFFFF)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Path
{
	int dest;
	int cost;

	friend bool operator>(const Path& p1, const Path& p2);
};

bool operator>(const Path& p1, const Path& p2)
{
	return p1.cost > p2.cost;
}
void dijkstra(vector<vector<Path>>& v, int start);

int dist[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	vector<vector<Path>> v(n + 1);

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
	}
	int start, end;
	cin >> start >> end;
	dijkstra(v, start);

	cout << dist[end];

	return 0;
}

void dijkstra(vector<vector<Path>>& v, int start)
{
	priority_queue<Path, vector<Path>, greater<Path>> pq;

	for (int i = 0; i < MAXN; i++)
	{
		dist[i] = INF;
	}
	dist[start] = 0;

	pq.push({ start, dist[start] });

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();
		if (dist[cur.dest] < cur.cost)
		{
			continue;
		}

		for (int i = 0; i < v[cur.dest].size(); i++)
		{
			auto next = v[cur.dest][i];
			if (dist[next.dest] > cur.cost + next.cost)
			{
				dist[next.dest] = cur.cost + next.cost;
				pq.push({ next.dest, dist[next.dest] });
			}
		}
	}
}