#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

int n, m, k;
vector<pair<int, char>> graph[501];
char card[1001];
int D[1001][501];

int solution(int index, int node)
{
	if (index > n)
	{
		return 0;
	}

	int& result = D[index][node];
	if (result >= 0)
	{
		return result;
	}

	result = 0;

	for (const auto& e : graph[node])
	{
		int next = e.first;
		result = ::max(result, solution(index + 1, next) + (card[index] == e.second ? 10 : 0));
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> card[i];
	}
	
	cin >> m >> k;
	for (int i = 0; i < k; i++)
	{
		int from, to;
		char c;
		cin >> from >> to >> c;
		graph[from].push_back(make_pair(to, c));
		graph[to].push_back(make_pair(from, c));
	}

	memset(D, -1, sizeof(D));

	cout << solution(1, 1);

	return 0;
}