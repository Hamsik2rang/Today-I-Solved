#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 9
int graph[MAXN][MAXN];
vector<pair<int, int>> virus;
int n, m;

int bfs()
{
	static int dr[]{ -1,0,1,0 };
	static int dc[]{ 0,-1,0,1 };
	int spread[MAXN][MAXN]{};
	bool visited[MAXN][MAXN]{};
	::memcpy(spread, graph, sizeof(graph));

	for (int i = 0; i < virus.size(); i++)
	{
		queue<pair<int, int>> q;
		q.push(virus[i]);
		visited[virus[i].first][virus[i].second] = true;
		while (!q.empty())
		{
			int cr = q.front().first;
			int cc = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nr = cr + dr[i];
				int nc = cc + dc[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= m || visited[nr][nc] || spread[nr][nc] == 1)
				{
					continue;
				}

				visited[nr][nc] = true;
				spread[nr][nc] = 2;
				q.push(make_pair(nr, nc));
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (spread[i][j] == 0)
			{
				result++;
			}
		}
	}

	return result;
}

int solution(int count)
{
	static int answer = 0;
	if (count == 3)
	{
		answer = max(answer, bfs());
		return answer;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == 0)
			{
				graph[i][j] = 1;
				solution(count + 1);
				graph[i][j] = 0;
			}
		}
	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
			{
				virus.push_back(make_pair(i, j));
			}
		}
	}

	cout << solution(0);

	return 0;
}