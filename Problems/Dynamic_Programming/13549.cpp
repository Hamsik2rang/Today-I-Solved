#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 100001

using namespace std;

int dist[MAXN]{};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < MAXN; i++)
	{
		dist[i] = 0x7fffffff;
	}

	queue<int> q;
	q.push(n);
	dist[n] = 0;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur == k)
		{
			cout << dist[cur];
			break;
		}

		if (cur > 0 && cur * 2 < MAXN && dist[cur * 2] > dist[cur])
		{
			dist[cur * 2] = dist[cur];
			q.push(cur * 2);
		}
		if (cur + 1 < MAXN && dist[cur + 1] > dist[cur] + 1)
		{
			dist[cur + 1] = dist[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && dist[cur - 1] > dist[cur] + 1)
		{
			dist[cur - 1] = dist[cur] + 1;
			q.push(cur - 1);
		}
	}

	return 0;
}