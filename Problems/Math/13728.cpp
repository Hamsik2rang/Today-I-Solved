// ref to https://www.cut-the-knot.org/arithmetic/algebra/FibonacciMatrix.shtml#nice
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define MOD 1'000'000'007
#define MAXN 100'001

int64_t fibo[MAXN];

int64_t GCD(int64_t a, int64_t b)
{
	if (a < b)
	{
		swap(a, b);
	}

	while (a % b)
	{
		int64_t mod = a % b;
		a = b;
		b = mod;
	}

	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 2;
	for (int i = 3; i <= n + 1; i++)
	{
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	}
	int64_t answer = 0;
	for (int i = 1; i <= n; i++)
	{
		answer += fibo[GCD(i + 1, n + 1) - 1];
		answer %= MOD;
	}

	cout << answer;

	return 0;
}