#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define MAXN 201

int parent[MAXN];

int FindSet(int v)
{
	if (v == parent[v])
	{
		return v;
	}
	parent[v] = FindSet(parent[v]);
	return parent[v];
}

void UnionSet(int u, int v)
{
	parent[FindSet(v)] = FindSet(u);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int num;
			cin >> num;
			if (num == 1)
			{
				UnionSet(j, i);
			}
		}
	}
	vector<int> travel(m);
	for (int i = 0; i < m; i++)
	{
		cin >> travel[i];
	}
	bool answer = true;
	for (int i = 0; i < m - 1; i++)
	{
		if (FindSet(travel[i]) == FindSet(travel[i + 1]))
		{
			continue;
		}
		answer = false;
		break;
	}
	cout << (answer ? "YES" : "NO");

	return 0;
}