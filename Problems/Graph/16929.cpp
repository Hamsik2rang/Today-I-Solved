#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAXN 51

bool answer;
int n, m;
string graph[MAXN];
bool check[MAXN][MAXN];

void dfs(int curRow, int curCol, int lastRow, int lastCol)
{
	static int dr[]{ -1, 0, 1, 0 };
	static int dc[]{ 0, -1, 0, 1 };

	check[curRow][curCol] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextRow = curRow + dr[i];
		int nextCol = curCol + dc[i];
		if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m)
		{
			continue;
		}

		if (graph[nextRow][nextCol] != graph[curRow][curCol] || (nextRow == lastRow && nextCol == lastCol))
		{
			continue;
		}

		// 사이클이 존재하는 경우
		if (check[nextRow][nextCol])
		{
			answer = true;
			return;
		}
		dfs(nextRow, nextCol, curRow, curCol);
		if (answer)
		{
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> graph[i];
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			if (!answer)
			{
				memset(check, false, sizeof(check));
				dfs(r, c, -1, -1);
			}
		}
	}

	cout << (answer ? "Yes" : "No");

	return 0;
}