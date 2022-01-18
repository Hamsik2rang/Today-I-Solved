#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

#define MAXN 20

using namespace std;

enum DIRECTION { EAST = 1, WEST, NORTH, SOUTH };
short board[MAXN][MAXN];
short dice[6];
int dr[4]{ 0, 0, -1, 1 };
int dc[4]{ 1, -1, 0, 0 };
int n, m, k;

void roll(int dir)
{
	int temp = dice[5];
	switch (dir)
	{
	case EAST:
		dice[5] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = temp;
		break;
	case WEST:
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = temp;
		break;
	case NORTH:
		dice[5] = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = temp;
		break;
	case SOUTH:
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = temp;
		break;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int cr = 0, cc = 0;
	cin >> n >> m >> cr >> cc >> k;

	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
			cin >> board[r][c];
	
	while(k--)
	{
		int dir;
		cin >> dir;
		int nr = cr + dr[dir - 1];
		int nc = cc + dc[dir - 1];
		if (!(nr < 0 || nc < 0 || nr >= n || nc >= m))
		{
			cr = nr;
			cc = nc;
			roll(dir);

			if (!board[cr][cc])
			{
				board[cr][cc] = dice[5];
			}
			else
			{
				dice[5] = board[cr][cc];
				board[cr][cc] = 0;
			}
			cout << dice[2] << "\n";
		}
	}

	return 0;
}