#include <iostream>
#include <algorithm>

using namespace std;

int arr[51];
int ans[51];
int n;

inline double GetDelta(int idx1, int idx2)
{
	return ((double)arr[idx1] - arr[idx2]) / (idx1 - idx2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i++)
	{
		double md = -1e9;

		for (int j = i + 1; j < n; j++)
		{
			double d = GetDelta(j, i);
			if (d <= md)
			{
				continue;
			}

			md = d;
			ans[i]++;
			ans[j]++;
		}
	}

	int answer = *max_element(ans, ans + n);
	cout << answer;

	return 0;
}