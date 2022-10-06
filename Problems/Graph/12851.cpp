#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define MAXN 100'001

int n, k;
int result[MAXN][2];

void bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));

	while (!q.empty())
	{
		auto curNum = q.front().first;
		auto curTime = q.front().second;
		q.pop();

		if (result[curNum][0] == curTime)
		{
			result[curNum][1]++;
		}
		else if (result[curNum][0] > curTime)
		{
			result[curNum][0] = curTime;
			result[curNum][1] = 1;
		}

		if (curNum * 2 < MAXN && result[curNum * 2][0] >= curTime + 1)
		{
			q.push(make_pair(curNum * 2, curTime + 1));
		}
		if (curNum + 1 < MAXN && result[curNum + 1][0] >= curTime + 1)
		{
			q.push(make_pair(curNum + 1, curTime + 1));
		}
		if (curNum - 1 >= 0 && result[curNum - 1][0] >= curTime + 1)
		{
			q.push(make_pair(curNum - 1, curTime + 1));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 0; i < MAXN; i++)
	{
		result[i][0] = 0x7fffffff;
		result[i][1] = 0;
	}
	bfs();
	std::cout << result[k][0] << "\n" << result[k][1];

	return 0;
}