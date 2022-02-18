#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

constexpr int MAXN(10'001);

uint32_t memo[MAXN];
int cost[21];
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
	{
		memset(memo, 0, sizeof(memo));
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> cost[i];
		}
		int m;
		cin >> m;
		memo[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = cost[i]; j <= m; j++)
			{
				memo[j] += memo[j - cost[i]];
			}
		}
		cout << memo[m] << "\n";
	}

	return 0;
}