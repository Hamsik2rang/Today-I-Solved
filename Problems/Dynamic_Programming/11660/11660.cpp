#include <iostream>

#define MAXN 1024

using namespace std;

int arr[MAXN + 1][MAXN + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
			arr[i][j] += arr[i][j - 1];
		}
		for (int j = 1; j <= n; j++)
		{
			arr[i][j] += arr[i - 1][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int answer = arr[y2][x2] - arr[y2][x1 - 1] - arr[y1 - 1][x2] + arr[y1 - 1][x1 - 1];
		cout << answer << "\n";
	}

	return 0;
}