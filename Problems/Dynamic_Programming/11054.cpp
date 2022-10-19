#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define MAXN 100'002

vector<int> input;
int fmemo[MAXN], bmemo[MAXN];
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (input[i] > input[j] && bmemo[i] < bmemo[j])
			{
				bmemo[i] = bmemo[j];
			}
		}
		bmemo[i]++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (input[i] > input[j] && fmemo[i] < fmemo[j])
			{
				fmemo[i] = fmemo[j];
			}
		}
		fmemo[i]++;
	}

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer = max(answer, fmemo[i] + bmemo[i] - 1);
	}
	cout << answer;

	return 0;
}