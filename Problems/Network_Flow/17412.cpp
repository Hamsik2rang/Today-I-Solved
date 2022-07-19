#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAXN 401

using namespace std;

int n, p; 
int cap[MAXN][MAXN];
int flow[MAXN][MAXN];
vector<int> v[MAXN];

int Solution()
{
	int answer = 0;
	
	while (true)
	{
		queue<int> q;
		int parent[MAXN]{};

		q.push(1);
		while (!q.empty() && !parent[2])
		{
			int cur = q.front();
			q.pop();

			for (int i = 0; i < v[cur].size(); i++)
			{
				int next = v[cur][i];
				if (cap[cur][next] - flow[cur][next] > 0 && !parent[next])
				{
					q.push(next);
					parent[next] = cur;
				}
			}
		}

		if (!parent[2])
		{
			break;
		}

		int index = 2;
		int size = 0x7fffffff;
		while (index != 1)
		{
			size = min(size, cap[parent[index]][index] - flow[parent[index]][index]);
			index = parent[index];
		}
		index = 2;
		while (index != 1)
		{
			flow[parent[index]][index] += size;
			flow[index][parent[index]] -= size;
			index = parent[index];
		}
		answer++;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> p;

	for (int i = 1; i <= p; i++)
	{
		int from;
		int to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
		cap[from][to] = 1;
	}

	cout << Solution();

	return 0;
}