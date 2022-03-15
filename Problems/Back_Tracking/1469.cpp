#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXX = 16;
const int MAXLEN = 32;

int n;
vector<int> v;
int arr[MAXLEN];
bool check[MAXX];

bool solution(int used)
{
	if (used >= n)
	{
		return true;
	}
	for (int i = 0; i < n * 2; i++)
	{
		if (arr[i] != -1)
		{
			continue;
		}
		for (int j = 0; j < n; j++)
		{
			int x = v[j];
			if (check[j] || (i + 1 + x) >= (n * 2) || arr[i + 1 + x] != -1)
			{
				continue;
			}
			check[j] = true;
			arr[i] = arr[i + 1 + x] = x;
			bool result = solution(used + 1);
			if (result)
			{
				return true;
			}
			check[j] = false;
			arr[i] = arr[i + 1 + x] = -1;
		}
	}
	return false;
}

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
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	memset(arr, -1, sizeof(arr));
	auto result = solution(0);
	if (result)
	{
		for (int i = 0; i < n * 2; i++)
		{
			cout << arr[i] << " ";
		}
	}
	else
	{
		cout << -1;
	}

	return 0;
}
