#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 100'001

int n, k;
bool check[MAXN];

int solution()
{
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));

	while (!q.empty())
	{
		int x = q.front().first;
		int sec = q.front().second;
		q.pop();

		if (check[x])
		{
			continue;
		}
		check[x] = true;

		if (x == k)
		{
			return sec;
		}

		if (x * 2 > 0 && x * 2 < MAXN && !check[x * 2])
		{
			q.push(make_pair(x * 2, sec + 1));
		}
		if (x + 1 >= 0 && x + 1 < MAXN && !check[x + 1])
		{
			q.push(make_pair(x + 1, sec + 1));
		}
		if (x - 1 >= 0 && x - 1 < MAXN && !check[x - 1])
		{
			q.push(make_pair(x - 1, sec + 1));
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	cout << solution();

	return 0;
}