#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 4001

int n, m;
int answer = 0x7fff00ff;
bool graph[MAXN][MAXN];
bool check[MAXN];
int friends[MAXN];

void dfs(int x, vector<int>& v)
{
	if (v.size() == 3)
	{
		if (graph[v[0]][v[1]] && graph[v[1]][v[2]] && graph[v[2]][v[0]])
		{
			answer = min(answer, friends[v[0]] + friends[v[1]] + friends[v[2]] - 6);
		}
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (x != 0 && (i == x || !graph[x][i] || check[i]))
		{
			continue;
		}
		check[i] = true;
		v.push_back(i);
		dfs(i, v);
		v.pop_back();
		check[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;

		graph[from][to] = true;
		graph[to][from] = true;
		friends[from]++;
		friends[to]++;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j || !graph[i][j])
			{
				continue;
			}

		}
	}
	vector<int> v;
	dfs(0, v);

	if (answer > 0x7fff0000)
	{
		cout << -1;
	}
	else
	{
		cout << answer;
	}

	return 0;
}