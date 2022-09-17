#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

#define MAXN 10001

vector<pair<pair<int, int>, int>> edges;
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
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		edges.push_back(make_pair(make_pair(from, to), cost));
	}

	sort(edges.begin(), edges.end(), [](const pair<pair<int, int>, int>& p1, const pair<pair<int, int>, int>& p2)->bool
		{
			return p1.second < p2.second;
		});

	int t = n - 1;
	int index = 0;
	int answer = 0;
	while (t)
	{
		auto cur = edges[index++];
		if (FindSet(cur.first.first) == FindSet(cur.first.second))
		{
			continue;
		}
		UnionSet(cur.first.first, cur.first.second);
		answer += cur.second;
		t--;
	}

	cout << answer;

	return 0;
}