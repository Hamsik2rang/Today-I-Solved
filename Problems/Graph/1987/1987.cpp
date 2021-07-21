#include <iostream>
#include <vector>

#define MAX_R 21
#define MAX_C 21

using namespace std;

int dr[]{ -1,0,1,0 };
int dc[]{ 0,-1,0,1 };

char alphabet[MAX_R][MAX_C]{};
bool check['z' - 'a' + 1]{ false };

int dfs(int row, int col, const int& maxRow, const int& maxCol, int answer)
{
	int result = answer;
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr < 0 || nr >= maxRow || nc < 0 || nc >= maxCol || check[alphabet[nr][nc] - 'A'])
			continue;
		
		check[alphabet[nr][nc] - 'A'] = true;
		int cur = dfs(nr, nc, maxRow, maxCol, answer + 1);
		check[alphabet[nr][nc] - 'A'] = false;
		result = result < cur ? cur : result;
	}
	return result;
}

int main()
{
	int r, c;
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> alphabet[i][j];
		}
	}
	check[alphabet[0][0] - 'A'] = true;
	int answer = dfs(0, 0, r, c, 1);

	cout << answer << endl;

	return 0;
}