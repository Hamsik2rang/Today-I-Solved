#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 17

int n;
int answer[MAXN][MAXN];
bool graph[MAXN][MAXN];

// �������� �װ��� ������ �� �ִ��� �Ǵ��ϴ� �Լ�
bool promise(const pair<int, int>& tail, const pair<int, int>& head)
{
	if (head.first < 1 || head.first > n || head.second < 1 || head.second > n)
	{
		return false;
	}


	if (head.first - tail.first == 1 && head.second - tail.second == 1)
	{
		return !(graph[tail.first][tail.second] || 
			graph[head.first][head.second] || 
			graph[tail.first][head.second] || 
			graph[head.first][tail.second]);
	}
	else
	{
		return !(graph[head.first][head.second] || 
			graph[tail.first][tail.second]);
	}
}

void solution(const pair<int, int>& tail, const pair<int, int>& head)
{
	if (!promise(tail, head))
	{
		return;
	}

	answer[head.first][head.second]++;
	// ������ �밢���� ������
	if (head.first - tail.first == 1 && head.second - tail.second == 1)
	{
		solution(head, make_pair(head.first, head.second + 1));
		solution(head, make_pair(head.first + 1, head.second + 1));
		solution(head, make_pair(head.first + 1, head.second));
	}
	// ������ ���η� ������
	else if (head.first - tail.first == 1)
	{
		solution(head, make_pair(head.first + 1, head.second + 1));
		solution(head, make_pair(head.first + 1, head.second));
	}
	// ������ ���η� ������
	else
	{
		solution(head, make_pair(head.first, head.second + 1));
		solution(head, make_pair(head.first + 1, head.second + 1));
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
		}
	}

	solution(make_pair(1, 1), make_pair(1, 2));

	cout << answer[n][n];

	return 0;
}