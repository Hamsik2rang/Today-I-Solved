#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;


vector<int> pos;
int answer[50]{ 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	// len / count of referee / pos for the referee to stand
	cin >> n >> m >> k;
	pos.reserve(k);
	for (int i = 0; i < k; i++)
	{
		int p;
		cin >> p;
		pos.push_back(p);
	}

	int start = 0;
	int end = pos.back() - pos.front();

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int lastIndex = 0;
		int lastPosCount = m - 1;
		int cur[50]{ 1	};
		for (int i = 1; i < pos.size() && lastPosCount; i++)
		{
			if (pos[i] - pos[lastIndex] >= mid)
			{
				lastIndex = i;
				lastPosCount--;
				cur[i] = 1;
			}
		}

		if (lastPosCount)
		{
			end = mid - 1;
		}
		else
		{
			memcpy(answer, cur, sizeof(answer));
			start = mid + 1;
		}
	}
	for (int i = 0; i < k; i++)
	{
		cout << answer[i];
	}

	return 0;
}