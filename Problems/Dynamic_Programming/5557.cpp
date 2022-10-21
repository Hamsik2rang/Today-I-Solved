#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAXN 101

int n;
int num[MAXN];
int64_t memo[MAXN][21];

int64_t solution()
{
	memo[0][num[0]] = 1;

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (memo[i - 1][j])
			{
				if (j + num[i] <= 20)
				{
					memo[i][j + num[i]] += memo[i - 1][j];
				}
				if (j - num[i] >= 0)
				{
					memo[i][j - num[i]] += memo[i - 1][j];
				}
			}
		}
	}

	return memo[n - 2][num[n - 1]];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}

	cout << solution();

	return 0;
}
