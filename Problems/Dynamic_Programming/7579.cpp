#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 101

int n, m, ans, sum;
int mem[MAXN], cost[MAXN];
int memo[MAXN][MAXN * MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> mem[i];
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i];
		sum += cost[i];
	}

	memo[0][mem[0]] = cost[0];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j - cost[i] >= 0)
			{
				memo[i][j] = max(memo[i][j], memo[i - 1][j - cost[i]] + mem[i]);
			}

			memo[i][j] = max(memo[i][j], memo[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum; i++)
	{
		if (memo[n][i] >= m)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}