/// ref https://js1jj2sk3.tistory.com/3

#include <iostream>
#include <algorithm>
#include <limits>

#define MAXK 501

using namespace std;

int d[MAXK][MAXK];
int chapter[MAXK];
int sum[MAXK];

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int k;
		cin >> k;
		for (int i = 1; i <= k; i++)
		{
			cin >> chapter[i];
			sum[i] = sum[i - 1] + chapter[i];
		}

		for (int i = 1; i < k; i++)
		{
			for (int j = 1; i + j <= k; j++)
			{
				d[j][i + j] = numeric_limits<int>::max();
				for (int m = j; m < i + j; m++)
				{
					d[j][i + j] = min(d[j][i + j], d[j][m] + d[m + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}
		cout << d[1][k] << endl;
	}

	return 0;
}