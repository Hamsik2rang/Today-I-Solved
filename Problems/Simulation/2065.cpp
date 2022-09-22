#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int m, t, n;
	cin >> m >> t >> n;
	queue<int> q[2];
	queue<int> index[2];
	for (int i = 0; i < n; i++)
	{
		int time;
		string pos;
		cin >> time >> pos;
		if (pos == "left")
		{
			q[0].push(time);
			index[0].push(i);
		}
		else
		{
			q[1].push(time);
			index[1].push(i);
		}
	}


	int loc = 1;
	int curTime = 0;
	int remainSit = m;
	vector<int> answer(n);
	while (!q[0].empty() || !q[1].empty())
	{
		loc = (loc + 1) % 2;
		remainSit = m;

		if (!q[loc].empty() && q[loc].front() <= curTime)
		{
			while (!q[loc].empty() && remainSit > 0 && q[loc].front() <= curTime)
			{
				answer[index[loc].front()] = curTime + t;
				remainSit--;
				q[loc].pop();
				index[loc].pop();
			}
		}
		else if (q[(loc + 1) % 2].empty() || !q[(loc + 1) % 2].empty() && !q[loc].empty() && (q[loc].front() < q[(loc + 1) % 2].front()))
		{
			curTime = q[loc].front();
			while (!q[loc].empty() && remainSit > 0 && q[loc].front() <= curTime)
			{
				answer[index[loc].front()] = curTime + t;
				remainSit--;
				q[loc].pop();
				index[loc].pop();
			}
		}
		else
		{
			curTime = q[(loc + 1) % 2].front() > curTime ? q[(loc + 1) % 2].front() : curTime;
		}

		curTime += t;
	}

	for (const auto& e : answer)
	{
		cout << e << "\n";
	}

	return 0;
}