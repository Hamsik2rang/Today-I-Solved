#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<uint64_t> ans;
	int n;
	cin >> n;

	if (n >= (1 << 10) - 1)
	{
		cout << -1;
		return 0;
	}
	// 11 1111 1111
	// 
	for (int i = 1; i < (1 << 10); i++)
	{
		int bit = i;
		uint64_t temp = 0;
		for (int j = 9; j >= 0; j--)
		{
			if (bit & (1 << j))
			{
				temp *= 10;
				temp += j;
			}
		}
		ans.push_back(temp);
	}
	
	sort(ans.begin(), ans.end());
	cout << ans[n];
	
	return 0;
}