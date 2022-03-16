#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

constexpr int MAXN = 1001;

vector<int> graph[MAXN];
int pre[MAXN];
int cost[MAXN];
int dist[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		memset(graph, 0, sizeof(graph));
		memset(pre, 0, sizeof(pre));
		memset(cost, 0, sizeof(cost));
		std::fill(dist, dist + MAXN, 0);

		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			cin >> cost[i];
		}

		for (int i = 1; i <= k; i++)
		{
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			pre[y]++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (!pre[i])
			{
				q.push(i);
				dist[i] = cost[i];
			}
		}

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (int i = 0; i < graph[cur].size(); i++)
			{
				auto next = graph[cur][i];
				if (dist[next] < cost[next] + dist[cur])
				{
					dist[next] = cost[next] + dist[cur];
					q.push(next);
				}
			}
		}
		int w;
		cin >> w;
		cout << dist[w] << "\n";
	}

	return 0;
}
