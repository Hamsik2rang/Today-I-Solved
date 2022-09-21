#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

#define MAXN 21

struct Compare
{
	bool operator()(pair<pair<int, int>, int>& p1, pair<pair<int, int>, int>& p2)
	{
		if (p1.second == p2.second)
		{
			if (p1.first.first == p2.first.first)
			{
				return p1.first.second > p2.first.second;
			}
			return p1.first.first > p2.first.first;
		}
		return p1.second > p2.second;
	}
};

int n;
int board[MAXN][MAXN];
int level = 2;
int eatCount;
int answer;
pair<int, int> startPos;

bool bfs()
{
	static int dr[]{ -1, 0, 1, 0 };
	static int dc[]{ 0, -1, 0, 1 };

	bool check[MAXN][MAXN]{ false };

	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, Compare> pq;
	queue<pair<pair<int, int>, int>> q;
	check[startPos.first][startPos.second] = true;
	board[startPos.first][startPos.second] = 0;
	q.push(make_pair(startPos, 0));
	while (!q.empty())
	{
		auto cur = q.front();
		auto cr = q.front().first.first;
		auto cc = q.front().first.second;
		auto ccnt = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= n || check[nr][nc] || board[nr][nc] > level)
			{
				continue;
			}

			check[nr][nc] = true;
			q.push(make_pair(make_pair(nr, nc), ccnt + 1));
			if (board[nr][nc] && board[nr][nc] < level)
			{
				pq.push(make_pair(make_pair(nr, nc), ccnt + 1));
			}
		}
	}

	if (pq.empty())
	{
		return false;
	}
	else
	{
		answer += pq.top().second;
		startPos = pq.top().first;
		return true;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				startPos = make_pair(i, j);
			}
		}
	}

	while (bfs())
	{
		eatCount++;
		if (eatCount == level)
		{
			level++;
			eatCount = 0;
		}
	}

	cout << answer;

	return 0;
}