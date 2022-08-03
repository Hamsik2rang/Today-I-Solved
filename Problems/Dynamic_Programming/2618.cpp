#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

#define MAXN 1001

int n, w;
vector<pair<int, int>> crime;
int memo[MAXN][MAXN];

int distance(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return (abs(p2.first - p1.first) + abs(p2.second - p1.second));
}

int solution(int a, int b)
{
	if (a == w || b == w)
	{
		return 0;
	}

	if (memo[a][b])
	{
		return memo[a][b];
	}
	int& cur = memo[a][b];

	int next = a < b ? b + 1 : a + 1;
	int aDist = 0;
	if (a == 0)
	{
		aDist = distance(make_pair(1, 1), crime[next]);
	}
	else
	{
		aDist = distance(crime[a], crime[next]);
	}

	int bDist = 0;
	if (b == 0)
	{
		bDist = distance(make_pair(n, n), crime[next]);
	}
	else
	{
		bDist = distance(crime[b], crime[next]);
	}
	int aNext = solution(next, b) + aDist;
	int bNext = solution(a, next) + bDist;
	cur = aNext < bNext ? aNext : bNext;

	return cur;
}

void print(int a, int b)
{
	if (a == w || b == w)
	{
		return;
	}

	int next = a < b ? b + 1 : a + 1;
	int aDist = 0;
	if (a == 0)
	{
		aDist = distance(make_pair(1, 1), crime[next]);
	}
	else
	{
		aDist = distance(crime[a], crime[next]);
	}

	int bDist = 0;
	if (b == 0)
	{
		bDist = distance(make_pair(n, n), crime[next]);
	}
	else
	{
		bDist = distance(crime[b], crime[next]);
	}

	if (memo[next][b] + aDist > memo[a][next] + bDist)
	{
		cout << 2 << "\n";
		print(a, next);
	}
	else
	{
		cout << 1 << "\n";
		print(next, b);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> w;
	crime.push_back(make_pair(0, 0));
	for (int i = 1; i <= w; i++)
	{
		int r, c;
		cin >> r >> c;
		crime.push_back(make_pair(r, c));
	}

	cout << solution(0, 0) << '\n';
	print(0, 0);

	return 0;
}