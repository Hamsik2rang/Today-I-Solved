#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAXN 501

using namespace std;

int matrix[MAXN][MAXN];
int memo[MAXN][MAXN];

int R, C;

int Search(int row, int col)
{
	if (memo[row][col] >= 0)
	{
		return memo[row][col];
	}
	memo[row][col] = 0;

	static int dr[]{ -1, 0, 1, 0 };
	static int dc[]{ 0, -1, 0, 1 };

	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (nr < 0 || nr > R || nc < 0 || nc > C ||
			matrix[row][col] >= matrix[nr][nc])
		{
			continue;
		}
		memo[row][col] += Search(nr, nc);
	}

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
			int height;
			cin >> height;
			matrix[i][j] = height;
			memo[i][j] = -1;
		}
	}
	memo[1][1] = 1;
	memo[R][C] = Search(R, C);
	cout << memo[R][C] << "\n";

	return 0;
}