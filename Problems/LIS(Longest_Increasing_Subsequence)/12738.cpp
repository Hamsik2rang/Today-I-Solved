#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (v.empty() || v.back() < num)
		{
			v.push_back(num);
		}
		else
		{
			auto iter = lower_bound(v.begin(), v.end(), num);
			*iter = num;
		}
	}
	cout << v.size();

	return 0;
}