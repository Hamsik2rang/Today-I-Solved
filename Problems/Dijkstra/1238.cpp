#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

#define MAXN 1001
#define INF 1'000'000'000

struct comparer
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return p1.second > p2.second;
	}
};

int n, m, x;
vector<pair<int, int>> graph[MAXN];
int dist[MAXN][MAXN];

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, comparer> pq;

	pq.push(make_pair(start, 0));
	dist[start][start] = 0;
	while (!pq.empty())
	{
		auto curNum = pq.top().first;
		auto curCost = pq.top().second;
		pq.pop();

		for (const auto& next : graph[curNum])
		{
			int nextNum = next.first;
			int nextCost = next.second;
			if (dist[start][nextNum] <= dist[start][curNum] + nextCost)
			{
				continue;
			}
			dist[start][nextNum] = dist[start][curNum] + nextCost;
			pq.push(make_pair(nextNum, dist[start][nextNum]));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> x;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, time;
		cin >> from >> to >> time;
		graph[from].push_back(make_pair(to, time));
	}

	for (int i = 1; i <= n; i++)
	{
		dijkstra(i);
	}
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, dist[i][x] + dist[x][i]);
	}
	cout << answer;

	return 0;
}