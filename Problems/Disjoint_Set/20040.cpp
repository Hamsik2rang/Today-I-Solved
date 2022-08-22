#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

using namespace std;

#define MAXN 500'001

int parent[MAXN];

int FindSet(int v)
{
	if (parent[v] == v)
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

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		if (FindSet(u) == FindSet(v))
		{
			cout << i;
			return 0;
		}
		UnionSet(u, v);
	}

	cout << 0;
	 
	return 0;
}