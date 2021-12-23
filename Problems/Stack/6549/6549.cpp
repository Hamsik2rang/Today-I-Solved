#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("input.txt", "r", stdin);

	do
	{
		int n;
		cin >> n;
		if (!n) break;
		
		//pair.first = height, second = index
		stack<pair<int, int>> st;
		unsigned long long answer = 0;

		for (int i = 0; i < n; i++)
		{
			int height;
			cin >> height;
			int index = i;

			while (!st.empty() && st.top().first >= height)
			{
				unsigned long long area = (unsigned long long)st.top().first * (i - st.top().second);
				answer = answer < area ? area : answer;
				index = st.top().second;
				st.pop();
			}
			st.push(make_pair(height, index));
		}

		while (!st.empty())
		{
			unsigned long long area = (unsigned long long)st.top().first * (n - st.top().second);
			answer = answer < area ? area : answer;
			st.pop();
		}
		cout << answer << "\n";

	} while (true);

	return 0;
}