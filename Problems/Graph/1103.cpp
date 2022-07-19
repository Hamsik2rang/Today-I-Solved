#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAXN 501

using namespace std;

int matrix[MAXN][MAXN];
int memo[MAXN][MAXN];
bool check[MAXN][MAXN];
bool bInfinite = false;

int R, C;

int Search(int row, int col)
{
	if (bInfinite)
	{
		return -1;
	}
	if (memo[row][col] >= 0)
	{
		return memo[row][col];
	}
	memo[row][col] = 1;
	check[row][col] = true;

	int dr[]{ -matrix[row][col], 0, matrix[row][col], 0 };
	int dc[]{ 0, -matrix[row][col], 0, matrix[row][col] };
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (nr < 0 || nr > R || nc < 0 || nc > C || matrix[nr][nc] < 0)
		{
			continue;
		}
		else if (check[nr][nc])
		{
			bInfinite = true;
			return -1;
		}
		result = max(result, Search(nr, nc));
	}
	memo[row][col] += result;
	check[row][col] = false;
	
	return memo[row][col];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			char c;
			int num;
			cin >> c;
			if (c == 'H')
			{
				num = -1;
			}
			else
			{
				num = c - '0';
			}
			matrix[i][j] = num;
			memo[i][j] = -1;
		}
	}
	memo[1][1] = Search(1, 1);
	if (bInfinite)
	{
		cout << -1 << "\n";
	}
	else
	{
		cout << memo[1][1] << "\n";
	}

	return 0;
}