#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	pair<int64_t, int64_t> point[3];
	for (int i = 0; i < 3; i++)
	{
		int64_t x, y;
		cin >> x >> y;
		point[i] = make_pair(x, y);
	}

	int64_t result = ((point[2].first - point[1].first) * (point[0].second - point[1].second))
		- ((point[2].second - point[1].second) * (point[0].first - point[1].first));
	if (result > 0)
	{
		cout << 1;
	}
	else if (result == 0)
	{
		cout << 0;
	}
	else
	{
		cout << -1;
	}

	return 0;
}