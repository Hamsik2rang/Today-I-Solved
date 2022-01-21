#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> v;

void solution(vector<int>& select)
{
	if (select.size() == m)
	{
		for (int& e : select)
			cout << e << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		select.push_back(v[i]);
		solution(select);
		select.pop_back();
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
	solution(select);

	return 0;
}