#include <iostream>
#include <queue>
#include <list>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// caution. in this problm, l is weight of bridge and w is length of bridge.
	int w, l, n;
	cin >> n >> w >> l;

	queue<int> q;
	list<pair<int,int>> bridge;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		q.push(temp);
	}

	int answer = 0;
	int curWeight= 0;
	while (!q.empty() || !bridge.empty())
	{
		answer++;
		for (auto it = bridge.begin(); it != bridge.end();)
		{
			if (--it->second == 0)
			{
				curWeight -= it->first;
				it = bridge.erase(it);
				continue;
			}
			it++;
		}

		if (!q.empty() && curWeight + q.front() <= l)
		{
			curWeight += q.front();
			bridge.push_back(make_pair(q.front(), w));
			q.pop();
		}
	}

	cout << answer;

	return 0;
}