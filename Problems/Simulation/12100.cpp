#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#define MAXN 20

using namespace std;

int board[MAXN][MAXN];
int n;

int findMax(int(*board)[MAXN])
{
	int maxNum = 0;
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < n; j++)
		{
			maxNum = maxNum < board[i][j] ? board[i][j] : maxNum;
		}
	}
	return maxNum;
}

void rotate(int (*board)[MAXN])
{
	int temp[MAXN][MAXN] { 0 };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = temp[n - 1 - j][i];
		}
	}
}

void merge(int(*board)[MAXN])
{
	int merged[MAXN];
	for (int i = 0; i < n; i++)
	{
		memset(merged, 0, sizeof(int) * MAXN);
		for (int j = 0, ptr = 0; j < n; j++)
		{
			if (board[i][j] == 0)
				continue;
			if (merged[ptr] == 0)
				merged[ptr] = board[i][j];
			else if (merged[ptr] == board[i][j])
				merged[ptr++] *= 2;
			else
				merged[++ptr] = board[i][j];
		}
		memcpy(board[i], merged, sizeof(int) * MAXN);
	}
}

int play(int (*board)[MAXN], int playCount)
{
	int answer = findMax(board);
	if (playCount == 0)
		return answer;

	for (int i = 0; i < 4; i++)
	{
		int curBoard[MAXN][MAXN]{ 0 };
		rotate(board);
		memcpy(curBoard, board, MAXN * MAXN * sizeof(int));
		merge(curBoard);
		int result = play(curBoard, playCount - 1);
		answer = answer < result ? result : answer;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
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

	int answer = play(board, 5);
	cout << answer;

	return 0;
}