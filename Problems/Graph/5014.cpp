#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>

using namespace std;

#define MAXN 1000001

int f, s, g, u, d;

int bfs()
{
	static bool check[MAXN]{ false };
	queue<pair<int, int>> q;
	check[s] = true;
	q.push(make_pair(s, 0));
	while (!q.empty())
	{
		auto curStair = q.front().first;
		auto curTime = q.front().second;
		q.pop();
		if (curStair == g)
		{
			return curTime;
		}

		if (curStair + u <= f && !check[curStair + u])
		{
			check[curStair + u] = true;
			q.push(make_pair(curStair + u, curTime + 1));
		}
		if (curStair - d > 0 && !check[curStair - d])
		{
			check[curStair - d] = true;
			q.push(make_pair(curStair - d, curTime + 1));
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> f >> s >> g >> u >> d;

	int result = bfs();
	cout << (result < 0 ? "use the stairs" : to_string(result));

	return 0;
}