#include <iostream>
#include <vector>

using namespace std;

bool check[9]{ false };

void solution(int n, int m, vector<int> v)
{
	if (!m)
	{
		for (const auto& e : v)
		{
			cout << e << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			v.push_back(i);
			solution(n, m - 1, v);
			v.pop_back();
			check[i] = false;
		}
	}
}

int main()
{
	int n, m;
	vector<int> v;
	
	cin >> n >> m;

	solution(n, m, v);

	return 0;
}