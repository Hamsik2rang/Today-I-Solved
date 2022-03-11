#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
int arr[8001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v;
	v.reserve(n);

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
		arr[temp + 4000]++;
	}

	sort(v.begin(), v.end());
	int mean = round((float)accumulate(v.begin(), v.end(), 0) / (float)n);
	int mid = v[n / 2];
	int mode = -4000;
	int mcount = 0;
	for (int i = 0; i < 8001; i++)
	{
		if (arr[i] > mcount)
		{
			mode = i;
			mcount = arr[i];
		}
	}
	for (int i = mode + 1; i < 8001; i++)
	{
		if (arr[i] == mcount)
		{
			mode = i;
			break;
		}
	}
	mode -= 4000;
	int range = *(v.end() - 1) - *v.begin();
	cout << mean << '\n' << mid << '\n' << mode << '\n' << range;
	
	return 0;
}