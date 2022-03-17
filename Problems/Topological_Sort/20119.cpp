// ref to https://4legs-study.tistory.com/93

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int MAXN = 200001;

struct Potion
{
	bool belong = false;
	vector<vector<int>> pre;
	vector<int> next;
};

vector<Potion> recipe(MAXN);

void bfs(int n)
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (recipe[i].belong)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		auto cur = recipe[q.front()];
		q.pop();

		for (int i = 0; i < cur.next.size(); i++)
		{
			auto next = cur.next[i];
			if (recipe[next].belong)
			{
				continue;
			}
			for (int j = 0; j < recipe[next].pre.size(); j++)
			{
				auto curRecipe = recipe[next].pre[j];
				bool canMade = true;
				for (int k = 0; k < curRecipe.size(); k++)
				{
					if (!recipe[curRecipe[k]].belong)
					{
						canMade = false;
						break;
					}
				}
				if (canMade)
				{
					recipe[next].belong = true;
					q.push(next);
					break;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n, m;
	cin >> n >> m;
	
	int cnt;
	vector<int> ingredient;
	for (int i = 0; i < m; i++)
	{
		cin >> cnt;
		ingredient.clear();
		for (int j = 0; j < cnt; j++)
		{
			int p;
			cin >> p;
			ingredient.push_back(p);
		}
		int r;
		cin >> r;
		for (int j = 0; j < cnt; j++)
		{
			recipe[ingredient[j]].next.push_back(r);
		}
		recipe[r].pre.push_back(ingredient);
	}

	cin >> cnt;
	for (int i = 0; i < cnt; i++)
	{
		int index;
		cin >> index;
		recipe[index].belong = true;
	}

	bfs(n);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (recipe[i].belong)
		{
			cnt++;
		}
	}
	cout << cnt << "\n";
	for (int i = 1; i <= n; i++)
	{
		if (recipe[i].belong)
		{
			cout << i << " ";
		}
	}

	return 0;
}
