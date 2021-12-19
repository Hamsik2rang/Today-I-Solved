#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	unordered_map<int, bool> m;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		m[v[i]] = true;
	}
	int x;
	cin >> x;
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int target = x - v[i];
		if (m.find(target) != m.end() && m[target])
		{
			answer++;
		}
	}
	cout << answer / 2;

	return 0;
}