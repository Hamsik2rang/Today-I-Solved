#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

#define MAXN 126
int graph[MAXN][MAXN];
int dist[MAXN][MAXN];

int dr[]{ -1,0,1,0 };
int dc[]{ 0,-1,0,1 };

struct compare
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return dist[p1.first][p1.second] > dist[p2.first][p2.second];
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 1;
	int n;
	while (true)
	{
		cin >> n;
		if (!n) 
		{
			break;
		}

		memset(graph, 0, sizeof(graph));
		memset(dist, 0, sizeof(dist));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> graph[i][j];
				dist[i][j] = 0x7fffff00;
			}
		}
		dist[0][0] = graph[0][0];
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
		pq.push(make_pair(0, 0));

		while (!pq.empty())
		{
			auto cur = pq.top();
			int& cr = cur.first;
			int& cc = cur.second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nr = cr + dr[i];
				int nc = cc + dc[i];

				if (nr < 0 || nr >= n || nc < 0 || nc >= n)
				{
					continue;
				}

				if (dist[cr][cc] + graph[nr][nc] < dist[nr][nc])
				{
					dist[nr][nc] = dist[cr][cc] + graph[nr][nc];
					pq.push(make_pair(nr, nc));
				}
			}
		}

		cout << "Problem " << cnt++ << ": " << dist[n - 1][n - 1] << "\n";
	}


	return 0;
}