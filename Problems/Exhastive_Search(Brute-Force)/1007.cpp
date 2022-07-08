#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <cstring>

#define MAXN 20

using namespace std;

int n;
bool check[MAXN]{ false };
vector<pair<long long, long long>> points;
double answer;

double GetLength()
{
	pair<long long, long long> start = { 0,0 };
	pair<long long, long long> end = { 0,0 };
	for (int i = 0; i < n; i++)
	{
		if (check[i])
		{
			start.first += points[i].first;
			start.second += points[i].second;
		}
		else
		{
			end.first += points[i].first;
			end.second += points[i].second;
		}
	}

	return sqrt((end.first - start.first) * (end.first - start.first) + (end.second - start.second) * (end.second - start.second));
}

void Solution(int x, int count)
{
	if (count == n / 2)
	{
		answer = min(GetLength(), answer);
		return;
	}
	for (int i = x; i < n; i++)
	{
		if (check[i])
		{
			continue;
		}
		check[i] = true;
		Solution(i + 1, count + 1);
		check[i] = false;
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int tc = 1; tc <= T; tc++)
	{
		points.clear();
		memset(check, 0, sizeof(check));
		answer = 1.7e9 + 732;

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			long long x, y;
			scanf("%lld %lld", &x, &y);
			points.push_back(make_pair(x, y));
		}
		Solution(0, 0);
		printf("%.7lf\n", answer);
	}

	return 0;
}