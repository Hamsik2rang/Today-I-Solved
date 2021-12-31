#include <iostream>
#include <vector>

using namespace std;

void solution(int n, int m, vector<int> v)
{
	if (!m)
	{
		for (const auto& e : v)
			cout << e << " ";
		cout << "\n";

		return;
	}

	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		solution(n, m - 1, v);
		v.pop_back();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v;

	solution(n, m, v);

	return 0;
}