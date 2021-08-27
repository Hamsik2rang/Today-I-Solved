#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++)
	{
		vector<int64_t> left, right, whole;
		int64_t n, m;
		cin >> n >> m;

		left.reserve(n);
		right.reserve(m);
		int64_t house;

		for (int i = 0; i < n; i++)
		{
			cin >> house;
			left.push_back(house);
		}
		sort(left.begin(), left.end());

		for (int i = 0; i < m; i++)
		{
			cin >> house;
			right.push_back(house);
		}
		sort(right.begin(), right.end());

		int64_t leftPtr = n - 1;
		int64_t rightPtr = m - 1;

		int64_t p = 0, q = 0;
		int64_t answer = 0;
		while (leftPtr >= 0 && rightPtr >= 0)
		{
			if (left[leftPtr] > right[rightPtr])
			{
				p++;
				if ((m * p) + (n * q) - (m * n) > 0)
				{
					answer = left[leftPtr];
					break;
				}
				leftPtr--;
			}
			else if (left[leftPtr] < right[rightPtr])
			{
				q++;
				if ((m * p) + (n * q) - (m * n) > 0)
				{
					answer = right[rightPtr];
					break;
				}
				rightPtr--;
			}
			else
			{
				p++, q++;
				if ((m * p) + (n * q) - (m * n) > 0)
				{
					answer = left[leftPtr];
					break;
				}
				leftPtr--, rightPtr--;
			}
		}
		if (rightPtr < 0)
		{
			while (leftPtr >= 0)
			{
				p++;
				if ((m * p) + (n * q) - (m * n) > 0)
				{
					answer = left[leftPtr];
					break;
				}
			}
		}
		else if (leftPtr < 0)
		{
			while (rightPtr >= 0)
			{
				q++;
				if ((m * p) + (n * q) - (m * n) > 0)
				{
					answer = right[rightPtr];
					break;
				}
			}
			answer = right[rightPtr];
		}
		cout << fixed << setprecision(1) << (double)answer << '\n';
	}

	return 0;
}