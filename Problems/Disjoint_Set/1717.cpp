#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int findSet(int v);
void unionSet(int u, int v);
inline bool isSame(int u, int v);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	parent.resize(n + 1);
	// Make set.
	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int cmd, u, v;
		cin >> cmd >> u >> v;
		if (cmd == 0)
		{
			unionSet(u, v);
		}
		else
		{
			if (isSame(u, v))
			{
				cout << "YES\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}

	return 0;
}

int findSet(int v)
{
	if (v == parent[v])
	{
		return v;
	}
	// automatically renew parent.
	parent[v] = findSet(parent[v]);
	return parent[v];
}

void unionSet(int u, int v)
{
	parent[findSet(v)] = findSet(u);
}

bool isSame(int u, int v)
{
	return findSet(u) == findSet(v);
}