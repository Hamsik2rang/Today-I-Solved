#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

#define MAXN 300'001

uint64_t n;
vector<int> v[MAXN];
vector<int> child[MAXN];
int subtreeSize[MAXN];
bool check[MAXN];

int64_t SetTree(int index)
{
	check[index] = true;
	subtreeSize[index] = 1;

	for (int i = 0; i < v[index].size(); i++)
	{
		auto next = v[index][i];
		if (check[next])
		{
			continue;
		}

		subtreeSize[index] += SetTree(next);
		child[index].push_back(next);
	}

	return subtreeSize[index];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	SetTree(1);
	uint64_t answer = 0;
	for (int i = 2; i <= n; i++)
	{
		uint64_t x = n - subtreeSize[i];
		answer += (n * (n - 1) / 2) - (x * (x - 1) / 2);
	}
	cout << answer;

	return 0;
}