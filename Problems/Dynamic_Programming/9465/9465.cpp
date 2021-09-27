#define MAXN 100001

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int sticker[MAXN][2]{ 1 };

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		memset(sticker, 0, sizeof(sticker));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> sticker[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> sticker[i][1];
		}
		sticker[1][0] += sticker[0][1];
		sticker[1][1] += sticker[0][0];

		for (int i = 2; i < n; i++)
		{
			sticker[i][0] += max(sticker[i - 1][1], sticker[i - 2][1]);
			sticker[i][1] += max(sticker[i - 1][0], sticker[i - 2][0]);
		}
		if (n > 0)
		{
			cout << max(sticker[n - 1][0], sticker[n - 1][1]) << endl;
		}
	}

	return 0;
}