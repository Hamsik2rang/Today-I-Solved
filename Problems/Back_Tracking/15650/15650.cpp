#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int n, m;

void solution(vector<int>& v, int index, int count)
{
	if (count == m)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
	}

	for (int i = index; i <= n; i++)
	{
		v.push_back(i);
		solution(v, i + 1, count + 1);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	vector<int> v;

	solution(v, 1, 0);

	return 0;
}