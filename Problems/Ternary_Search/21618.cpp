#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

using namespace std;

constexpr int MAXN = 200'001;
constexpr int MAXD = 1e9;

int n;
int p[MAXN];
int w[MAXN];
int d[MAXN];

long long calc(int x)
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (abs(x - p[i]) <= d[i])
		{
			continue;
		}
		long long hearingDist = min(abs((x - d[i]) - p[i]), abs((x + d[i]) - p[i]));
		sum += hearingDist * (long long)w[i];
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	int s = MAXD;
	int e = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i] >> w[i] >> d[i];
		s = min(s, p[i]);
		e = max(e, p[i]);
	}
	if (n == 1)
	{
		cout << 0;
		return 0;
	}

	long long sum = 1e18;
	// In ternary search, exit condition is not composed with s(start) and e(end).
	// just set loop time properly.
	for (int i = 0; i < 60; i++)
	{
		int delta = (e - s) / 3;
		int l = s + delta;
		int r = e - delta;

		long long lr = calc(l);
		long long rr = calc(r);
		sum = min(lr, sum);
		sum = min(rr, sum);
		if (lr > rr)
		{
			s = l;
		}
		else
		{
			e = r;
		}
	}
	cout << sum;

	return 0;
}