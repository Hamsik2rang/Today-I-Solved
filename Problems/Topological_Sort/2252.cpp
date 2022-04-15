#include <iostream>
#include <vector>
#include <queue>

#define MAXN 32'001
#define MAXM 100'000

using namespace std;

struct Student
{
	bool check = false;
	vector<int> front;
	vector<int> back;
}student[MAXN];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> answer;
	answer.reserve(n);

	for (int i = 0; i < m; i++)
	{
		int front, back;
		cin >> front >> back;
		student[front].back.push_back(back);
		student[back].front.push_back(front);
	}

	for (int i = 1; i <= n; i++)
	{
		if (student[i].front.empty())
		{
			queue<int> q;
			q.push(i);
			while (!q.empty())
			{
				int cur = q.front();
				student[cur].check = true;
				answer.push_back(cur);
				q.pop();

				for (int i = 0; i < student[cur].back.size(); i++)
				{
					int next = student[cur].back[i];
					bool hasFront = false;
					for (const auto& e : student[next].front)
					{
						if (!student[e].check)
						{
							hasFront = true;
							break;
						}
					}

					if (hasFront)
					{
						continue;
					}

					q.push(next);
				}
			}
		}
	}

	for (const auto& e : answer)
	{
		cout << e << " ";
	}

	return 0;
}