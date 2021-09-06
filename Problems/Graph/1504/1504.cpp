#define _CRT_SECURE_NO_WARNINGS
#define MAXN (801)
#define MAXE (200000)
#define INF (0x7fffffff)

#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

void dijkstra(int, int);

vector<vector<pair<int, int>>> graph;
int dist[4][MAXN];
int path[4][MAXN];
int N, E;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> N >> E;

	graph.resize(N + 1);

	for (int i = 0; i < E; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
		graph[to].push_back(make_pair(from, cost));
	}

	int hasTo[2];
	cin >> hasTo[0] >> hasTo[1];

	dijkstra(1, 0);
	dijkstra(hasTo[0], 1);
	dijkstra(hasTo[1], 2);

	if (dist[0][hasTo[0]] == INF || dist[0][hasTo[1]] == INF || dist[1][hasTo[1]] == INF || dist[2][hasTo[0]] == INF)
	{
		cout << -1;
	}
	else
	{
						//1 -> A -> B -> N									// 1 -> B -> A -> N
		auto answer = dist[0][hasTo[0]] + dist[1][hasTo[1]] + dist[2][N] < dist[0][hasTo[1]] + dist[2][hasTo[0]] + dist[1][N]
			? dist[0][hasTo[0]] + dist[1][hasTo[1]] + dist[2][N]
			: dist[0][hasTo[1]] + dist[2][hasTo[0]] + dist[1][N];
		cout << answer;
	}

	return 0;
}

void dijkstra(int start, int index)
{
	for (int i = 0; i < MAXN; i++)
	{
		dist[index][i] = INF;
		path[index][i] = -1;
	}
	dist[index][start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(start, dist[index][start]));

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		for (int i = 0; i < graph[cur.first].size(); i++)
		{
			auto next = graph[cur.first][i];
			if (dist[index][next.first] > next.second + cur.second)
			{
				dist[index][next.first] = next.second + cur.second;
				pq.push(make_pair(next.first, dist[index][next.first]));
			}
		}
		if(!pq.empty())
		{
			path[index][pq.top().first] = cur.first;
		}
	}
}