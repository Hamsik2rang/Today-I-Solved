#define _CRT_SECURE_NO_WARNINGS
#define MAXN 200

#include <iostream>

using namespace std;

int graph[MAXN][MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		if (!graph[from][to] || graph[from][to] > cost)
		{
			graph[from][to] = cost;
		}
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
						graph[i][j] = graph[i][j] > graph[i][k] + graph[k][j] ? graph[i][k] + graph[k][j] : graph[i][j];
					}
					else
					{
						graph[i][j] = graph[i][k] + graph[k][j];
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}