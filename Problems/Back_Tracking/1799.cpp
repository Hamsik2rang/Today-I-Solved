#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int board[11][11];
bool ld[20];	// r minus c, left diagonal
bool rd[20]; // r plus c, right diagonal
int answer[2];

void solution(int row, int col, const int startIndex, int count)
{
	if (row >= n)
	{
		answer[startIndex] = max(answer[startIndex], count);
		return;
	}

	if (col >= n)
	{
		row += 1;
		col = col % 2 ? 0 : 1;
	}


	if (board[row][col] && !(ld[n + row - col] || rd[row + col]))
	{
		auto templd = ld[n + row - col];
		auto temprd = rd[row + col];
		ld[n + row - col] = rd[row + col] = true;
		solution(row, col + 2, startIndex, count + 1);
		ld[n + row - col] = templd;
		rd[row + col] = temprd;

	}
	solution(row, col + 2, startIndex, count);
}

int main(void)
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
		}
	}
	solution(0, 0, 0, 0);
	solution(0, 1, 1, 0);
	cout << answer[0] + answer[1];


	return 0;
}
