#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

#define MAXN 100001
#define MAXDIST 10001

using namespace std;

struct Pos
{
	int x;
	int y;
};

struct compareX
{
	bool operator()(const Pos& p1, const Pos& p2) const
	{
		if (p1.x == p2.x)
		{
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	}
};

struct compareY
{
	bool operator()(const Pos& p1, const Pos& p2) const
	{
		if (p1.y == p2.y)
		{
			return p1.x < p2.x;
		}
		return p1.y < p2.y;
	}
};

inline int getSquareDist(Pos p1, Pos p2)
{
	return ((p2.x - p1.x) * (p2.x - p1.x)) + ((p2.y - p1.y) * (p2.y - p1.y));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<Pos> point(n);

	for (int i = 0; i < n; i++)
	{
		cin >> point[i].x >> point[i].y;
	}

	sort(point.begin(), point.end(), compareX());

	set<Pos, compareY> candidate = { point[0], point[1] };
	int answer = getSquareDist(point[0], point[1]);
	int start = 0;
	for (int i = 2; i < point.size(); i++)
	{
		while (start < i)
		{
			int dx = point[i].x - point[start].x;
			if (dx * dx > answer)
			{
				candidate.erase(point[start++]);
			}
			else
			{
				break;
			}
		}

		int dist = sqrt((double)answer) + 1;
		Pos lowest = Pos{ -MAXDIST, point[i].y - dist };
		Pos highest = Pos{ MAXDIST, point[i].y + dist };

		auto lb = candidate.lower_bound(lowest);
		auto ub = candidate.upper_bound(highest);

		while (lb != ub)
		{
			answer = min(answer, getSquareDist(*lb, point[i]));
			lb++;
		}
		candidate.insert(point[i]);
	}
	cout << answer;

	return 0;
}