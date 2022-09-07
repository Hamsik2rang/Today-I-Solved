#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

#define MAXN 101

int item[MAXN];
int graph[MAXN][MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	for (int i = 0; i < r; i++)
	{
		int from, to, distance;
		cin >> from >> to >> distance;
		graph[from][to] = graph[to][from] = distance;
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
				{
					continue;
				}

				if (graph[i][k] && graph[k][j])
				{
					if (graph[i][j])
					{
						graph[i][j] = graph[i][k] + graph[k][j] > graph[i][j] ? graph[i][j] : graph[i][k] + graph[k][j];
					}
					else
					{
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		int result = item[i];
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] && graph[i][j] <= m)
			{
				result += item[j];
			}
		}
		answer = max(answer, result);
	}

	cout << answer;

	return 0;
}