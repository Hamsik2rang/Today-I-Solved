#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <math.h>

using namespace std;

#define MAXN 101

vector<pair<pair<int, int>, float>> stars;
int parent[MAXN];

int FindSet(int v)
{
	if (parent[v] == v)
	{
		return v;
	}
	parent[v] = FindSet(parent[v]);
	return parent[v];
}

void UnionSet(int u, int v)
{
	parent[FindSet(v)] = FindSet(u);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i <= n; i++)
	{
		parent[i] = i;
	}

	vector<pair<float, float>> v;
	for (int i = 0; i < n; i++)
	{
		float x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			float len = sqrtf((v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
			stars.push_back(make_pair(make_pair(i + 1, j + 1), len));
		}
	}

	sort(stars.begin(), stars.end(), [](const pair<pair<int, int>, float>& p1, const pair<pair<int, int>, float>& p2)->bool
		{
			return p1.second < p2.second;
		});

	int index = 0;
	int t = n - 1;
	float answer = 0.0f;
	while (t)
	{
		auto& cur = stars[index++];
		if (FindSet(cur.first.first) == FindSet(cur.first.second))
		{
			continue;
		}

		UnionSet(cur.first.first, cur.first.second);
		answer += cur.second;
		t--;
	}
	cout << fixed << setprecision(2) << answer;

	return 0;
}