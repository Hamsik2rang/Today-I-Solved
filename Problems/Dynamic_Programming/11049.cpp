#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define MAXN 501

int n;
pair<int, int> mat[MAXN];
int memo[MAXN][MAXN];

int solution(int start, int end)
{
	if (memo[start][end])
	{
		return memo[start][end];
	}

	if (start + 1 == end)
	{
		return mat[start].first * mat[start].second * mat[end].second;
	}
	else if (start == end)
	{
		return 0;
	}

	int result = 0x7fffffff;
	for (int i = start; i < end; i++)
	{
		result = min(result, (solution(start, i) + solution(i + 1, end) + (mat[start].first * mat[i].second * mat[end].second)));
	}

	memo[start][end] = result;

	return memo[start][end];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> r >> c;
		mat[i] = make_pair(r, c);
	}

	cout << solution(0, n - 1);

	return 0;
}