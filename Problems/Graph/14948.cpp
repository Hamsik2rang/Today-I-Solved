#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 101

int n, m;
int graph[MAXN][MAXN];
int memo[2][MAXN][MAXN];

struct compare
{
	bool operator()(const pair<pair<int, int>, bool>& p1, const pair<pair<int, int>, bool>& p2)
	{
		return memo[p1.second][p1.first.first][p1.first.second] > memo[p2.second][p2.first.first][p2.first.second];
	}
};


int solution()
{
	static int dr[]{ -1,0,1,0 };
	static int dc[]{ 0,-1,0,1 };

	priority_queue<pair<pair<int, int>, bool>, vector<pair<pair<int, int>, bool>>, compare> pq;
	pq.push(make_pair(make_pair(0, 0), false));
	memo[0][0][0] = memo[1][0][0] = graph[0][0];
	while (!pq.empty())
	{
		int cr = pq.top().first.first;
		int cc = pq.top().first.second;
		bool cu = pq.top().second;
		pq.pop();

		if (cr == n - 1 && cc == m - 1)
		{
			return memo[cu][cr][cc];
		}

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m || 
				memo[cu][nr][nc] >= 0)
			{
				continue;
			}

			if (!cu)
			{
				int jr = nr + dr[i];
				int jc = nc + dc[i];
				if (!(jr < 0 || jr >= n || jc < 0 || jc >= m || memo[true][jr][jc] >= 0))
				{
					memo[true][jr][jc] = max(memo[cu][cr][cc], graph[jr][jc]);
					pq.push(make_pair(make_pair(jr, jc), true));
				}
			}
			memo[cu][nr][nc] = max(memo[cu][cr][cc], graph[nr][nc]);
			pq.push(make_pair(make_pair(nr, nc), cu));
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
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			memo[0][i][j] = memo[1][i][j] = -1;
		}
	}

	cout << solution();

	return 0;
}