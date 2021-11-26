#include <iostream>
#include <algorithm>

#define MAXN 500000

using namespace std;

int arr[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		auto ub = upper_bound(arr, arr + n, temp);
		auto lb = lower_bound(arr, arr + n, temp);

		cout << ub - lb << " ";
	}

	return 0;
}