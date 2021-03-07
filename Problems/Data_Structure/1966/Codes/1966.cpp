#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		int n, m;

		cin >> n >> m;

		int maxPriority = 0;
		for (int i = 0; i < n; i++)
		{
			int priority;
			cin >> priority;
			if (maxPriority < priority)
			{
				maxPriority = priority;
			}
			q.push(make_pair(priority, i));
			pq.push(priority);
		}
		int count = 0;

		while (!q.empty())
		{
			auto front = q.front();
			q.pop();
			if (pq.top() == front.first)
			{
				pq.pop();
				count++;
				if (m == front.second)
				{
					cout << count << '\n';
					break;
				}
			}
			else
			{
				q.push(front);
			}
		}
	}

	return 0;
}