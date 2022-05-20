#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>

using namespace std;

int n, e, v1, v2;
vector<pair<int, int>> graph[801];
int dist[801];

struct comp
{
	bool operator()(const pair<int,int>& p1, const pair<int,int>& p2)
	{
		return p1.second > p2.second;
	}
};

void dijkstra(int start)
{
	for (int i = 0; i < 801; i++)
	{
		dist[i] = 0x7fffffff;
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	pq.push(make_pair(start, 0));
	dist[start] = 0;

	while (!pq.empty())
	{
		auto cur = pq.top();
		pq.pop();

		for (int i = 0; i < graph[cur.first].size(); i++)
		{
			auto next = graph[cur.first][i];
			if (dist[next.first] > dist[cur.first] + next.second)
			{
				dist[next.first] = dist[cur.first] + next.second;
				pq.push(make_pair(next.first, dist[next.first]));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);

	cin >> n >> e;

	for (int i = 1; i <= e; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back(make_pair(to, cost));
		graph[to].push_back(make_pair(from, cost));
	}

	cin >> v1 >> v2;
	
	int answer = 0;
	dijkstra(1);
	int startToV1 = dist[v1];
	int startToV2 = dist[v2];
	dijkstra(v1);
	int v1ToV2 = dist[v2];
	int v1ToN = dist[n];
	dijkstra(v2);
	int v2ToN = dist[n];
	
	if (v1ToV2 == 0x7fffffff)
	{
		cout << -1;
	}
	else
	{
		answer = ::min(startToV1 + v1ToV2 + v2ToN, startToV2 + v1ToV2 + v1ToN);
		if (answer < 0)
		{
			cout << -1;
			return 0;
		}
		cout << answer;
	}

	return 0;
}