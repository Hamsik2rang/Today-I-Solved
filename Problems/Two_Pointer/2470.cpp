#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> sol(n);

	for (int i = 0; i < n; i++) cin >> sol[i];

	sort(sol.begin(), sol.end());

	auto alkali = sol.begin(), acid = sol.end() - 1;
	pair<int, int> answer(make_pair(0, 0));
	int min = 0x7fffffff;
	while (alkali < acid)
	{
		auto mix = *acid + *alkali;
		auto result = abs(mix);
		if (result <= min)
		{
			min = result;
			answer.first = *alkali;
			answer.second = *acid;
		}
		if (mix == 0) break;
		else if (mix < 0) alkali++;
		else acid--;
	}

	cout << answer.first << " " << answer.second;
	
	return 0;
}