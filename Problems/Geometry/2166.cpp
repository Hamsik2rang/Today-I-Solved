#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int64_t, int64_t>> point;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		point.push_back(make_pair(x, y));
	}
	pair<int64_t, int64_t>& a = point[0];
	double answer = 0;
	for (int i = 1; i < n - 1; i++)
	{
		auto& b = point[i];
		auto& c = point[i + 1];
		
		pair<int64_t, int64_t> v1 = make_pair(b.first - a.first, b.second - a.second);
		pair<int64_t, int64_t> v2 = make_pair(c.first - a.first, c.second - a.second);
		answer += (v1.first * v2.second - v1.second * v2.first);
	}
	answer = abs(answer) / 2.0f;
	cout << fixed << setprecision(1) << answer;

	return 0;
}