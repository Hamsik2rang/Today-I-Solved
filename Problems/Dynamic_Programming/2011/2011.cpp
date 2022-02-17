#include <iostream>

using namespace std;

constexpr int MAXLEN(5'001);
constexpr int MOD(1'000'000);

string s;
int memo[MAXLEN]{ 1,1, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
	if (s[0] == '0')
	{
		cout << 0;
	}
	else
	{
		for (int i = 2; i <= s.length(); i++)
		{
			if (s[i - 1] != '0')
			{
				memo[i] += memo[i - 1] % MOD;
			}
			int n = ((s[i - 2] - '0') * 10) + (s[i - 1] - '0');
			if (n >= 10 && n <= 26)
			{
				memo[i] += memo[i - 2] % MOD;
			}
			memo[i] %= MOD;
		}
		cout << memo[s.length()];
	}

	return 0;
}