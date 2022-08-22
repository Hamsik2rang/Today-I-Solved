#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<uint64_t> v;
vector<uint64_t> selected;

void solution(int index)
{
	if (!selected.empty())
	{
		uint64_t num = 0;
		for (int i = selected.size() - 1; i >= 0; i--)
		{
			num *= 10;
			num += selected[i];
		}
		v.push_back(num);
	}

	for (int i = index; i < 10; i++)
	{
		selected.push_back(i);
		solution(i + 1);
		selected.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	if (n >= 1023)
	{
		cout << -1;
		return 0;
	}

	solution(0);
	sort(v.begin(), v.end());
	cout << v[n];

	return 0;
}