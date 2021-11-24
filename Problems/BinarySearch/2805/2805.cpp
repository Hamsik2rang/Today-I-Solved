#include <iostream>
#include <vector>

using namespace std;

uint64_t lowerBound(const vector<int>& v, int min, int max, int target);

int main()
{
	int n, m;
	cin >> n >> m;
	int max = 0;
	vector<int> tree(n);

	for (int i = 0; i < n; i++)
	{
		cin >> tree[i];
		max = max < tree[i] ? tree[i] : max;
	}

	cout << lowerBound(tree, 0, max, m);

	return 0;
}

uint64_t lowerBound(const vector<int>& v, int min, int max, int target)
{
	int ans = 0;
	while (min <= max)
	{
		int height = (min + max) / 2;
		uint64_t len = 0;
		for (int i = 0; i < v.size(); i++)
		{
			len += (v[i] > height ? v[i] - height : 0);
		}

		if (len >= static_cast<uint64_t>(target))
		{
			ans = height;
			min = height + 1;
		}
		else
		{
			max = height - 1;
		}
	}
	return ans;
}