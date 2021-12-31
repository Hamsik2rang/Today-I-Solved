#include <iostream>
#include <vector>

using namespace std;

bool promising(vector<int>& board, int index)
{
	for (int i = 0; i < index; i++)
	{
		if (board[i] == board[index] || abs(board[i] - board[index]) == abs(i - index))
			return false;
	}

	return true;
}

int solution(vector<int>& board, const int& n, int index)
{
	if (index == board.size())	return 1;

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		board[index] = i;
		if (!promising(board, index)) continue;

		answer += solution(board, n, index + 1);
	}
	return answer;
}

int main()
{
	int n;
	cin >> n;
	vector<int> board(n);

	cout << solution(board, n, 0) << endl;

	return 0;
}