#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define MAXN 40001

struct Node
{
	int height = 0;
	int dist = 0;
	int parent = 0;
	vector<int> children;

}node[MAXN];

vector<pair<int, int>> v[MAXN];

void SetTree(int x, int parent, int dist, int height)
{
	static bool check[MAXN]{ false };
	check[x] = true;
	node[x].dist = dist;
	node[x].parent = parent;
	node[x].height = height;
	for (int i = 0; i < v[x].size(); i++)
	{
		int& next = v[x][i].first;
		int& nextDist = v[x][i].second;
		if (check[next])
		{
			continue;
		}
		node[x].children.push_back(next);

		SetTree(next, x, nextDist, height + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back(make_pair(to, dist));
		v[to].push_back(make_pair(from, dist));
	}

	SetTree(1, 0, 0 , 0);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		int aDist = 0;
		int bDist = 0;
		cin >> a >> b;

		while (node[a].height > node[b].height)
		{
			aDist += node[a].dist;
			a = node[a].parent;
		}
		while (node[a].height < node[b].height)
		{
			bDist += node[b].dist;
			b = node[b].parent;
		}

		while (a != b)
		{
			aDist += node[a].dist;
			bDist += node[b].dist;
			a = node[a].parent;
			b = node[b].parent;
		}
		cout << aDist + bDist << "\n";
	}

	return 0;
}