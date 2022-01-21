#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_LOTTO_COUNT 6

using namespace std;

vector<int> v;
int n;

void solution(vector<int> select, int index)
{
	if (select.size() == MAX_LOTTO_COUNT)
	{
		for (const auto& e : select)
			cout << e << " ";
		cout << "\n";
		return;
	}

	for (int i = index; i < n; i++)
	{
		select.push_back(v[i]);
		solution(select, i + 1);
		select.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{

		cin >> n;
		if (n == 0)
			break;
		v.clear();
		v.reserve(n);
		for (int i = 0; i < n; i++)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		vector<int> select;
		solution(select, 0);
		cout << "\n";
	}

	return 0;
}