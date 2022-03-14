#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr int MAXN = 1'500'001;
constexpr int MAXT = 50;

int arr[MAXN][2];
int memo[MAXN];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i][0] >> arr[i][1];
	}

	for (int i = n; i >= 0; i--)
	{
		memo[i] = memo[i + 1];
		if (i + arr[i][0] <= n)
		{
			memo[i] = max(memo[i + arr[i][0]] + arr[i][1], memo[i]);
		}
	}
	cout << *max_element(memo, memo + n);

	return 0;
}
