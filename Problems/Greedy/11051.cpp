#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN(1'000'001);
int maxCost[MAXN];
int cost[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		memset(maxCost, 0, sizeof(maxCost));
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < n; i++)
		{
			cin >> cost[i];
		}

		for (int i = n - 1; i >= 0; --i)
		{
			maxCost[i] = maxCost[i + 1] > cost[i] ? maxCost[i + 1] : cost[i];
		}
		long long answer = 0;
		for (int i = 0; i < n; i++)
		{
			answer += (long long)(maxCost[i] - cost[i]);
		}
		cout << answer << "\n";
	}

	return 0;
}