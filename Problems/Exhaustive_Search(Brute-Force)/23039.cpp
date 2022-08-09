#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN 6
#define MOD 5

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n;
	bool graph[MAXN][MAXN]{};
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from][to] = graph[to][from] = true;
	}

	if (n == 10)
	{
		cout << -1 << "\n";
		return 0;
	}

	int answer = 0;

	while (true)
	{
		int count[MAXN][MAXN]{};
		for (int i = 1; i < MAXN - 1; i++)
		{
			for (int j = i + 1; j < MAXN; j++)
			{
				// 같은 정점 혹은 인접 정점, 혹은 실이 연결되지 않은 정점이면 pass
				if (abs(i % MOD - j % MOD) <= 1 || abs(i - j) <= 1 || !graph[i][j])
				{
					continue;
				}
				// 선택된 두 정점 외 나머지 정점들 중 비인접 정점 간선 찾기
				for (int k = 1; k < MAXN - 1; k++)
				{
					if (k == i || k == j)
					{
						continue;
					}

					for (int m = k + 1; m < MAXN; m++)
					{
						if (m == i || m == j)
						{
							continue;
						}

						if (abs(k % MOD - m % MOD) <= 1 || abs(k - m) <= 1 || !graph[k][m])
						{
							continue;
						}

						count[i][j]++;
						count[j][i]++;
					}
				}
			}
		}

		int intersect[MAXN]{};
		int max = 0;
		int index = 0;
		for (int i = 1; i < MAXN; i++)
		{
			for (int j = 1; j < MAXN; j++)
			{
				intersect[i] += count[i][j];
			}
			if (max < intersect[i])
			{
				max = intersect[i];
				index = i;
			}
		}

		if (max == 0)
		{
			break;
		}

		else
		{
			for (int i = 1; i < MAXN; i++)
			{
				for (int j = 1; j < MAXN; j++)
				{
					if (i == index || j == index)
					{
						graph[i][j] = 0;
					}
				}
			}
		}

		answer++;
	}

	cout << answer;

	return 0;
}