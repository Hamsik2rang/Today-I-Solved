#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct comp
{
	bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
	{
		return lhs.second < rhs.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> jewel;
	vector<int> knapsack;

	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		jewel.push_back(make_pair(m, v));
	}

	for (int i = 0; i < k; i++)
	{
		int m;
		cin >> m;
		knapsack.push_back(m);
	}

	sort(knapsack.begin(), knapsack.end());
	sort(jewel.begin(), jewel.end(), [](pair<int, int>& lhs, pair<int, int>& rhs)->bool {
		if (lhs.first == rhs.first)
			return lhs.second > rhs.second;
		return lhs.first < rhs.first;
		});

	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	uint64_t answer = 0u;
	for (int i = 0, j = 0; i < k; i++)
	{
		auto cur = knapsack[i];
		while (j < n && jewel[j].first <= cur)
		{
			pq.push(jewel[j++]);
		}
		if (!pq.empty())
		{
			answer += pq.top().second;
			pq.pop();
		}
	}

	cout << answer;

	return 0;
}