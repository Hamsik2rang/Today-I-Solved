#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>

#define MAXN 50

using namespace std;

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> selected;

int calcDist()
{
	int dist = 0;
	for (const auto& h : house)
	{
		int cd = 0x7fffff0f;
		for (const auto& c : selected)
		{
			cd = min(cd, abs(h.first - c.first) + abs(h.second - c.second));
		}
		dist += cd;
	}
	return dist;
}

int solution(int index)
{
	if (selected.size() == m)
		return calcDist();

	int answer = 0x7fffff0f;
	for (int i = index; i < chicken.size(); i++)
	{
		selected.push_back(chicken[i]);
		int result = solution(i + 1);
		selected.pop_back();
		answer = min(answer, result);
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n * n; i++)
	{
		int info;
		cin >> info;

		if (info == 1)
			house.push_back(make_pair(i / n, i % n));
		else if (info == 2)
			chicken.push_back(make_pair(i / n, i % n));
	}
	vector<pair<int, int>> s;
	int answer = solution(0);
	cout << answer;

	return 0;
}