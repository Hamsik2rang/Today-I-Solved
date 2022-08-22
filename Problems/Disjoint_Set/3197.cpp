#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <utility>
#include <cstring>

using namespace std;

#define MAXN 1501

pair<int, int> parent[MAXN][MAXN];
vector<pair<int, int>> swan;
string lake[MAXN];
vector<pair<int, int>> ice[2];
bool check[MAXN][MAXN];
int R, C;

int dr[]{ -1, 0, 1, 0 };
int dc[]{ 0, -1, 0, 1 };


pair<int, int> FindSet(int r, int c)
{
	if (parent[r][c] == make_pair(r, c))
	{
		return parent[r][c];
	}
	parent[r][c] = FindSet(parent[r][c].first, parent[r][c].second);

	return parent[r][c];
}

void UnionSet(int r0, int c0, int r1, int c1)
{
	pair<int, int> u = FindSet(r0, c0);
	pair<int, int> v = FindSet(r1, c1);
	parent[v.first][v.second] = u;
}

void MakeSet(int r, int c)
{
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	parent[r][c] = make_pair(r, c);
	while (!q.empty())
	{
		auto cur = q.front();
		int cr = cur.first;
		int cc = cur.second;
		q.pop();

		if (lake[cr][cc] == 'L')
		{
			swan.push_back(make_pair(cr, cc));
			lake[cr][cc] = '.';
		}

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || check[nr][nc])
			{
				continue;
			}
			if (lake[nr][nc] == 'X')
			{
				ice[0].push_back(make_pair(nr, nc));
				check[nr][nc] = true;
				continue;
			}

			parent[nr][nc] = make_pair(r, c);
			check[nr][nc] = true;
			q.push(make_pair(nr, nc));
		}
	}
}

void Update()
{
	static int index = 0;
	const int curIndex = index;
	index = (index + 1) % 2;

	for (int i = 0; i < ice[curIndex].size(); i++)
	{
		auto& cur = ice[curIndex][i];
		int cr = cur.first;
		int cc = cur.second;
		if (lake[cr][cc] == '.')
		{
			continue;
		}
		lake[cr][cc] = '.';

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C)
			{
				continue;
			}

			if (lake[nr][nc] == 'X')
			{
				ice[index].push_back(make_pair(nr, nc));
			}
			if (lake[nr][nc] == '.')
			{
				UnionSet(nr, nc, cr, cc);
			}
		}
	}
	ice[curIndex].clear();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("labudovi.i02", "r", stdin);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		cin >> lake[i];
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (lake[i][j] != 'X' && !check[i][j])
			{
				MakeSet(i, j);
			}
			else if (lake[i][j] == 'X')
			{
				parent[i][j] = make_pair(i, j);
			}
		}
	}

	int answer = 0;
	while (true)
	{
		Update();
		answer++;
		auto s1 = FindSet(swan[0].first, swan[0].second);
		auto s2 = FindSet(swan[1].first, swan[1].second);
		if (s1 == s2)
		{
			break;
		}
	}
	cout << answer;

	return 0;
}