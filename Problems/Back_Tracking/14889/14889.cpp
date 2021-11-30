#include <iostream>
#include <vector>
#include <algorithm>

#define MAXN 21

using namespace std;

int graph[MAXN][MAXN];
int answer = 0x7fffffff;

void dfs(int n, vector<int>v);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> graph[i][j];
		}
	}
	vector<int> v;
	dfs(n, v);
	
	cout << answer;

	return 0;
}

void dfs(int n, vector<int>v)
{
	if (v.size() == n / 2)
	{
		vector<int> another;
		for (int i = 1, j = 0; i <= n; i++)
		{
			if (find(v.begin(), v.end(), i) == v.end())
			{
				another.push_back(i);
			}
		}
		int sum = 0, anotherSum = 0;
		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				sum += graph[v[i]][v[j]] + graph[v[j]][v[i]];
				anotherSum += graph[another[i]][another[j]] + graph[another[j]][another[i]];
			}
		}
		int diff = abs(sum - anotherSum);
		answer = answer > diff ? diff : answer;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!v.empty() && v[v.size() - 1] >= i) continue;
		v.push_back(i);
		dfs(n, v);
		v.pop_back();
	}
}