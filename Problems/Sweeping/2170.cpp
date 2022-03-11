#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

vector<pair<int, int>> lines;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	lines.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		lines.push_back(make_pair(start, end));
	}
	sort(lines.begin(), lines.end());
	int answer = 0;
	int start = lines[0].first;
	int end = lines[0].second;
	for (int i = 1; i < n; i++)
	{
		if (lines[i].first > end)
		{
			answer += end - start;
			start = lines[i].first;
			end = lines[i].second;
		}
		end = std::max(end, lines[i].second);
	}
	answer += end - start;
	cout << answer;

	return 0;
}