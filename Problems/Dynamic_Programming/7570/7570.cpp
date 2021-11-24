#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 1000001

using namespace std;

vector<int> memo(MAXN);

int main()
{
	int n;
	cin >> n;
	vector<int> child(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> child[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (memo[child[i] - 1] == 0)
		{
			memo[child[i]] = 1;
		}
		else
		{
			memo[child[i]] = memo[child[i] - 1] + 1;
		}
	}

	auto answer = n - *max_element(memo.begin(), memo.end());
	cout << answer;

	return 0;
}