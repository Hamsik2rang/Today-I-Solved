#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAXN = 10001;

vector<int> v[MAXN];
int cost[MAXN];
int d[MAXN];
int pre[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	
	queue<int> q;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int preCnt;
		cin >> cost[i] >> pre[i];
		if (pre[i])
		{
			for (int j = 0; j < pre[i]; j++)
			{
				int p;
				cin >> p;
				v[p].push_back(i);
			}
		}
		else
		{
			q.push(i);
			d[i] = cost[i];
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (d[next] < cost[next] + d[cur])
			{
				d[next] = cost[next] + d[cur];
				q.push(next);
			}
		}
	}
	cout << *max_element(d + 1, d + n + 1);

	return 0;
}