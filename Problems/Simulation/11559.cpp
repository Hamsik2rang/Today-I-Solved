#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>

#define MAXR 12
#define MAXC 6

using namespace std;

char board[MAXR][MAXC];
int chain;
int dr[4]{ -1,0,1,0 };
int dc[4]{ 0,-1,0,1 };

void update()
{
	char tempCol[MAXR]{ 0 };
	for (int c = 0; c < MAXC; c++)
	{
		memset(tempCol, '.', sizeof(tempCol));
		int ptr = 0;
		for (int r = MAXR - 1; r >=0; r--)
		{
			if (board[r][c] == '.')
				continue;
			else 
				tempCol[ptr++] = board[r][c];
		}

		for (int r = MAXR-1; r >=0; r--)
		{
			board[r][c] = tempCol[MAXR - r - 1];
		}
	}
}

bool burstable(int r, int c)
{
	if (board[r][c] == '.')
		return false;

	bool check[MAXR][MAXC]{ false };
	// first = row, second = col
	queue<pair<int,int>> q;
	check[r][c] = true;
	q.push(make_pair(r, c));
	int puyoCnt = 0;
	while (!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		puyoCnt++;

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];
			if (nr < 0 || nc < 0 || nr >= MAXR || nc >= MAXC || check[nr][nc] || (board[nr][nc] != board[cr][cc]))
				continue;
			check[nr][nc] = true;
			q.push(make_pair(nr, nc));
		}
	}

	return puyoCnt >= 4;
}

void burst(int r, int c)
{
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	char color = board[r][c];
	board[r][c] = '.';

	while (!q.empty())
	{
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = cr + dr[i];
			int nc = cc + dc[i];

			if (nr < 0 || nc < 0 || nr >= MAXR || nc >= MAXC || board[nr][nc] != color)
				continue;
		
			q.push(make_pair(nr, nc));
			board[nr][nc] = '.';
		}
	}
}

void play()
{
	update();

	bool isBursted = false;
	for (int r = MAXR - 1; r >= 0; r--)
	{
		for (int c = 0; c < MAXC; c++)
		{
			if (burstable(r, c))
			{
				burst(r, c);
				isBursted = true;
			}
		}
	}
	if(isBursted)
	{
		chain++;
		play();
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < MAXR; i++)
		for (int j = 0; j < MAXC; j++)
			cin >> board[i][j];

	play();
	cout << chain;

	return 0;
}