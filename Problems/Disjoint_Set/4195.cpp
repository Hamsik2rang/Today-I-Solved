#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define MAXN 200'005

int parent[MAXN];
map<string, int> m;
int index;

int FindSet(int v)
{
	if (parent[v] < 0)
	{
		return v;
	}

	parent[v] = FindSet(parent[v]);
	return parent[v];
}

void UnionSet(int u, int v)
{
	int uRoot = FindSet(u);
	int vRoot = FindSet(v);
	if (uRoot == vRoot)
	{
		return;
	}
	parent[uRoot] += parent[vRoot];
	parent[vRoot] = uRoot;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		m.clear();
		for (int i = 0; i < MAXN; i++)
		{
			parent[i] = -1;
		}
		index = 1;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string a, b;
			cin >> a >> b;
			if (!m[a])
			{
				m[a] = index++;
			}
			if (!m[b])
			{
				m[b] = index++;
			}

			UnionSet(m[a], m[b]);
			cout << -parent[FindSet(m[a])] << "\n";
		}
	}

	return 0;
}