#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <utility>
#include <cmath>

#define MAXN 101
#define MAXK 100001

using namespace std;

int n, k;

pair<int, int> knapsack[MAXN];
int D[MAXN][MAXK];

int solution(int index, int weight)
{
	if (index > n)
	{
		return 0;
	}
	
	int& result = D[index][weight];
	if (result)
	{
		return result;
	}
	result = solution(index + 1, weight);
	if (weight + knapsack[index].first <= k)
	{
		result = ::max(result, solution(index + 1, weight + knapsack[index].first) + knapsack[index].second);
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> knapsack[i].first >> knapsack[i].second;
	}

	cout << solution(1, 0);

	return 0;
}