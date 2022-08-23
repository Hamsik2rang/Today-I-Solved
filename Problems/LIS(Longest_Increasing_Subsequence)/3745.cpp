#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n)
	{
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			int b;
			cin >> b;

			if (v.empty() || v.back() < b)
			{
				v.push_back(b);
			}
			else
			{
				int index = lower_bound(v.begin(), v.end(), b) - v.begin();
				v[index] = b;
			}
		}
		cout << v.size() << "\n";
	}

	return 0;
}