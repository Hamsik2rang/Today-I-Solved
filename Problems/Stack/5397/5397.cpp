#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		stack<char> left, right;
		string s;
		cin >> s;

		for (const auto& e : s)
		{
			switch (e)
			{
			case '<':
				if (!left.empty())
				{
					right.push(left.top());
					left.pop();
				}
				break;
			case '>':
				if (!right.empty())
				{
					left.push(right.top());
					right.pop();
				}
				break;
			case '-':
				if (!left.empty())
				{
					left.pop();
				}
				break;
			default:
				left.push(e);
				break;
			}
		}

		while (!left.empty())
		{
			right.push(left.top());
			left.pop();
		}
		while (!right.empty())
		{
			cout << right.top();
			right.pop();
		}
		cout << "\n";
	}

	return 0;
}