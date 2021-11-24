#include <iostream>

#define MAXN 10000000
#define MAXRANGE 10001

using namespace std;

int arr[MAXRANGE];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		arr[temp]++;
	}

	for (int i = 1; i < MAXRANGE; i++)
	{
		if (arr[i] == 0) continue;
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << '\n';
		}
	}

	return 0;
}