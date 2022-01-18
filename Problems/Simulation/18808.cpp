#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAXN 40
#define MAXR 10

using namespace std;

bool notebook[MAXN][MAXN];
bool sticker[MAXR][MAXR];
int n, m, k;
int r, c;

void rotate()
{
	bool temp[MAXR][MAXR]{};
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			temp[j][r - 1 - i] = sticker[i][j];
		}
	}
	memset(sticker, false, sizeof(sticker));
    memcpy(sticker, temp, sizeof(sticker));
	swap(r, c);
}

bool pastable(int row, int col)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (row + i < 0 || col + j < 0 || row + i >= n || col + j >= m)
				return false;
			else if (notebook[row + i][col + j] && sticker[i][j])
				return false;
		}
	}
	return true;
}

void paste(int row, int col)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			notebook[row + i][col + j] = sticker[i][j] ? true : notebook[row + i][col + j];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> k;
	while (k--)
	{
		memset(sticker, 0, sizeof(sticker));
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> sticker[i][j];
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int row = 0; row <= n - r; row++)
			{
				for (int col = 0; col <= m - c; col++)
				{
					if (pastable(row, col))
					{
						paste(row, col);
						goto lb_next;
					}
				}
			}
			rotate();
		}
lb_next:;
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (notebook[i][j])
				answer++;
		}
	}
	cout << answer;

	return 0;
}