#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

#define MAXN 1001

int n, m;

bool board[MAXN][MAXN];
int dist[2][MAXN][MAXN];

int solution()
{
	static int dr[]{ -1, 0, 1, 0 };
	static int dc[]{ 0, -1, 0, 1 };

	queue<pair<pair<int, int>, bool>> q;
	q.push(make_pair(make_pair(0, 0), false));
	dist[0][0][0] = dist[1][0][0] = 1;

	while (!q.empty())
	{
		int cr = q.front().first.first;
		int cc = q.front().first.second;
		int hasBroken = q.front().second;
		q.pop();

		if (cr == n - 1 && cc == m - 1)
		{
			return dist[hasBroken][cr][cc];
		}

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m || (board[nr][nc] && hasBroken))
			{
				continue;
			}

			if (board[nr][nc] && dist[1][nr][nc] == 0)
			{
				dist[1][nr][nc] = dist[hasBroken][cr][cc] + 1;
				q.push(make_pair(make_pair(nr, nc), true));
			}
			else if (!board[nr][nc] && dist[hasBroken][nr][nc] == 0)
			{
				dist[hasBroken][nr][nc]= dist[hasBroken][cr][cc] + 1;
				q.push(make_pair(make_pair(nr, nc), hasBroken));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == '1')
			{
				board[i][j] = true;
			}
		}
	}
	cout << solution();


	return 0;
}