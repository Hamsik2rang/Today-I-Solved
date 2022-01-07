#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int n = 5;
string classroom[5];
bool check[5][5];
vector<int> selected;
int answer;

int isPromiseChoice(int row, int col)
{
	static int dr[] = { 1,  0, -1, 0 };
	static int dc[] = { 0, -1, 0, 1 };

	int answer = 1;
	check[row][col] = true;
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || check[nr][nc])
			continue;
		answer += isPromiseChoice(nr, nc);
	}
	return answer;
}

bool isAnswer()
{
	int somCount = 0;
	for (int i = 0; i < 7; i++)
	{
		int row = selected[i] / 5;
		int col = selected[i] % 5;
		if (classroom[row][col] == 'S')
			somCount++;
	}
	return somCount >= 4;
}

void solution(int index)
{
	if (selected.size() == 7)
	{
		memset(check, true, sizeof(bool) * 25);
		for (int i = 0; i < selected.size(); i++)
		{
			int row = selected[i] / 5;
			int col = selected[i] % 5;
			check[row][col] = false;
		}
		if (7 > isPromiseChoice(selected[0] / 5, selected[0] % 5))
		{
			return;
		}

		if(isAnswer())
			answer++;

		return;
	}

	for (int i = index; i < 25; i++)
	{
		selected.push_back(i);
		solution(i + 1);
		selected.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 5; i++)
		cin >> classroom[i];

	solution(0);
	cout << answer;

	return 0;
}