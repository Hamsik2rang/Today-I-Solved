#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<bool> check;
int n, m;

void solution(vector<int>& select)
{
	if (select.size() == m)
	{
		for (const auto& e : select)
			cout << e << " ";
		cout << "\n";
		return;
	}

	int last = 0;
	for (int i = 0; i < n; i++)
	{
		if (check[i] || v[i] == last) continue;

		check[i] = true;
		select.push_back(v[i]);
		last = v[i];
		solution(select);
		select.pop_back();
		check[i] = false;
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
		check.push_back(false);
	}

	sort(v.begin(), v.end());
	vector<int> select;
	solution(select);

	return 0;
}