#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, m;

void solution(vector<int> select, int index)
{
	if (select.size() == m)
	{
		for (const auto& e : select)
			cout << e << " ";
		cout << "\n";
		return;
	}
	int last = 0;
	for (int i = index; i < n; i++)
	{
		if (v[i] == last)
			continue;

		select.push_back(v[i]);
		solution(select, i);
		select.pop_back();
		last = v[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	vector<int> select;
	solution(select, 0);
	return 0;
}