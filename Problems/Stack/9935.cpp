#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string explosion;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	string s;
	cin >> s >> explosion;

	vector<char> stk;
	for (const auto& c : s)
	{
		stk.push_back(c);
		if (stk.size() < explosion.length())
		{
			continue;
		}
		bool promise = true;
		for (int i = 0; i < explosion.length(); i++)
		{
			if (stk[stk.size() - explosion.length() + i] != explosion[i])
			{
				promise = false;
				break;
			}
		}
		if (promise)
		{
			for (int i = 0; i < explosion.length(); i++)
			{
				stk.pop_back();
			}
		}
	}

	if (stk.empty())
	{
		cout << "FRULA";
		return 0;
	}
	for (const auto& e : stk)
	{
		cout << e;
	}

	return 0;
}