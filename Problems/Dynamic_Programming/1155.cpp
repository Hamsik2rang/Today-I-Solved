#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

#define MAXN 31

using namespace std;

uint64_t answer[MAXN][3];
int poll[MAXN][3];
vector<int> order[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < 6; i++)
	{
		string s;
		cin >> s;
		order[s[0] - 'A'].push_back(s[1] - 'A');
	}

	for (int i = 0; i < 3; i++)
	{
		answer[1][i] = 1;
		poll[1][i] = order[i][0];
	}

	for (int index = 2; index <= n; index++)
	{
		for (int i = 0; i < 3; i++)
		{
			answer[index][i] = answer[index - 1][i];
			int j = poll[index - 1][i];
			int k = 3 - i - j;

			answer[index][i]++;

			if (poll[index - 1][j] == k)
			{
				answer[index][i] += answer[index - 1][j];
				poll[index][i] = k;
				continue;
			}

			answer[index][i] += answer[index - 1][j];
			answer[index][i]++;
			answer[index][i] += answer[index - 1][i];
			poll[index][i] = poll[index - 1][i];
		}
	}

	cout << answer[n][0];

	return 0;
}