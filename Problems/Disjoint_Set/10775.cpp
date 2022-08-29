#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

#define MAXN 100'001

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

	int g, p;
	cin >> g >> p;
	for (int i = 0; i <= g; i++)
	{
		parent[i] = i;
	}

	int answer = 0;
	for (int i = 0; i < p; i++)
	{
		int n;
		cin >> n;

		int root = FindSet(n);
		if (root == 0)
		{
			break;
		}
		parent[root] = root - 1;
		answer++;
	}
	cout << answer;

	return 0;
}