#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 100001

struct Point
{
	int64_t x;
	int64_t y;
	int64_t dx;
	int64_t dy;

	bool operator<(const Point& p)
	{
		if (y == p.y)
		{
			return x < p.x;
		}
		return y < p.y;
	}
};

vector<Point> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	p.reserve(n);

	int lowerIndex = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		p.push_back({ x, y, 0, 0});
		if (p[lowerIndex].y > y)
		{
			lowerIndex = i;
		}
	}
	sort(p.begin(), p.end());

	for (int i = 1; i < n; i++)
	{
		p[i].dx = p[i].x - p[0].x;
		p[i].dy = p[i].y - p[0].y;
	}
	sort(p.begin() + 1, p.end(), [](Point& p1, Point& p2)->bool {
			int64_t result = p1.dx * p2.dy - p2.dx * p1.dy;
			if (result)
				return result > 0;
			else
				return p1 < p2;

		});

	stack<Point> stk;
	stk.push(p[0]);
	stk.push(p[1]);
	for (int i = 2; i < n; i++)
	{
		auto& next = p[i];
		while (stk.size() > 1)
		{
			auto second = stk.top();
			stk.pop();
			auto first = stk.top();

			if ((next.x - second.x) * (first.y - second.y) - (next.y - second.y) * (first.x - second.x) > 0)
			{
				stk.push(second);
				break;
			}
		}
		stk.push(next);	
	}

	cout << stk.size();

	return 0;
}