#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int memo[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);

	char a[1002], b[1002];
	cin >> (a + 1) >> (b + 1);
	int i, j;
	for (i = 1; a[i]; i++)
	{
		for (j = 1; b[j]; j++)
		{
			if (a[i] == b[j])
			{
				memo[i][j] = memo[i - 1][j - 1] + 1;
			}
			else
			{
				memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
			}
		}
	}
	cout << memo[i - 1][j - 1];

	return 0;
}