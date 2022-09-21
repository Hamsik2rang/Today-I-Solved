#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define MAXN 10'001

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n, m, t;
	cin >> n >> m >> t;
	queue<pair<int, int>> q[2];
	queue<int> index[2];
	for (int i = 0; i < n; i++)
	{
		int location, weight, readyTime;
		cin >> location >> weight >> readyTime;

		if (location == 0)
		{
			q[0].push(make_pair(weight, readyTime));
			index[0].push(i);
		}
		else
		{
			q[1].push(make_pair(weight, readyTime));
			index[1].push(i);
		}
	}

	int truckLoc = 0;
	int curTime = 0;
	vector<pair<int, int>> answer(n);
	while (!q[0].empty() || !q[1].empty())
	{
		int cur = truckLoc++ % 2;
		int remainingWeight = m;
		if (q[cur].empty())
		{
			curTime += t;
			continue;
		}

		if ((q[cur].front().second > curTime && q[(cur + 1) % 2].front().second > curTime) || 
			(q[cur].front().second > curTime && q[(cur + 1) % 2].empty()))
		{
			if (q[(cur + 1) % 2].empty() || q[cur].front().second <= q[(cur + 1) % 2].front().second)
			{
				curTime = q[cur].front().second;
			}
			else
			{
				curTime = q[(cur + 1) % 2].front().second;
			}
		}

		while (!q[cur].empty() && q[cur].front().second <= curTime && remainingWeight > 0)
		{
			if (q[cur].front().first > remainingWeight)
			{
				q[cur].front().first -= remainingWeight;
				remainingWeight = 0;
				answer[index[cur].front()].first = curTime;
			}
			else
			{
				remainingWeight -= q[cur].front().first;
				q[cur].pop();
				if (!answer[index[cur].front()].first)
				{
					answer[index[cur].front()].first = curTime;
				}
				answer[index[cur].front()].second = curTime + t;
				index[cur].pop();
			}
		}

		curTime += t;
	}

	for (const auto& e : answer)
	{
		cout << e.first << " " << e.second << "\n";
	}

	return 0;
}