#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> v;
	v.push_back(64);
	int n;

	cin >> n;
	while (true)
	{
		if (accumulate(v.begin(), v.end(), 0) == n)
		{
			break;
		}
		v.back() /= 2;
		if (accumulate(v.begin(), v.end(), 0) < n)
		{
			v.push_back(v.back());
		}
	}

	cout << v.size();

	return 0;
}