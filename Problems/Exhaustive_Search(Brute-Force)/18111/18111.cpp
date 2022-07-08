#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 500
#define MAXM 500

using namespace std;

int terrain[MAXN][MAXM];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, b;
	cin >> n >> m >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> terrain[i][j];
		}
	}
	int minTime = 0x7fffffff;
	int maxHeight = -1;
	for (int i = 0; i <= 256; i++)
	{
		int curBlock = b;
		int curTime = 0;
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				// lower than current height(i)
				if (terrain[j][k] - i < 0)
				{
					curTime += i - terrain[j][k];
					curBlock -= (i - terrain[j][k]);
				}
				// higher than current height(i)
				else if (terrain[j][k] - i > 0)
				{	
					curTime += (terrain[j][k] - i) * 2;
					curBlock += (terrain[j][k] - i);
				}
			}
		}
		// If it is impossible
		if (curBlock < 0)
		{
			continue;
		}
		if (curTime <= minTime && maxHeight < i)
		{
			maxHeight = i;
			minTime = curTime;
		}
	}

	cout << minTime << " " << maxHeight << endl;

	return 0;
}