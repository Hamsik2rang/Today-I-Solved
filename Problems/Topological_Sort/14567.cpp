#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

constexpr int MAXN = 1001;

vector<int> v[MAXN];
int semester[MAXN];
int pre[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int before, after;
		cin >> before >> after;
		v[before].push_back(after);
		pre[after]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!pre[i])
		{
			q.push(i);
			semester[i] = 1;
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++)
		{
			auto next = v[cur][i];
			if (semester[next] < semester[cur] + 1)
			{
				semester[next] = semester[cur] + 1;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << semester[i] << " ";
	}

	return 0;
}