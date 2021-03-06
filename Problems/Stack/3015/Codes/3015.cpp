#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	stack<pair<int, int>> s;
	int n;
	cin >> n;

	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		int tall;
		cin >> tall;

		while (!s.empty() && s.top().first < tall)
		{
			ans += s.top().second;
			s.pop();
		}

		if (s.empty())
			s.push(make_pair(tall, 1));
		else
		{
			if (s.top().first == tall)
			{
				ans += s.top().second;
				if (s.size() > 1)
					ans++;
				s.top().second++;
			}
			else
			{
				s.push(make_pair(tall, 1));
				ans++;
			}
		}
	}

	std::cout << ans;

	return 0;
}