#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAXN 501

using namespace std;

int matrix[MAXN][MAXN];
int memo[MAXN][MAXN];

int N;

int Search(int row, int col)
{
	static int dr[]{ -1, 0, 1, 0 };
	static int dc[]{ 0, -1, 0, 1 };
	
	if (memo[row][col])
	{
		return memo[row][col];
	}
	memo[row][col] = 1;

	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (nr < 0 || nr > N || nc < 0 || nc > N || 
			matrix[nr][nc] <= matrix[row][col])
		{
			continue;
		}
		result = max(result, Search(nr, nc));
	}
	memo[row][col] += result;
	
	return memo[row][col];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> matrix[i][j];
		}
	}
	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			memo[i][j] = Search(i, j);
			answer = answer < memo[i][j] ? memo[i][j] : answer;
		}
	}
	cout << answer << "\n";

	return 0;
}