#include <iostream>
#include <queue>
#include <cstring>

#define MAXN 100001

using namespace std;

struct Node
{
	int num;
	int weight;
};

void bfs(int start);

vector<vector<Node>> tree(MAXN);
bool check[MAXN]{ false };
int dist[MAXN];
int max;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		int from, to, weight;
		cin >> from >> to >> weight;
		tree[from].push_back({ to, weight });
		tree[to].push_back({ from, weight });
	}

	bfs(1);
	int start{ 1 };
	for (int i = 2; i <= n; i++)
	{
		if (dist[i] > dist[start])
		{
			start = i;
		}
	}

	bfs(start);
	int answer = dist[1];
	for (int i = 2; i <= n; i++)
	{
		if (answer < dist[i])
		{
			answer = dist[i];
		}
	}
	cout << answer;

	return 0;
}

void bfs(int start)
{
	memset(check, false, sizeof(check));
	memset(dist, 0, sizeof(dist));
	queue<Node> q;
	
	q.push({ start, 0 });
	check[start] = true;
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < tree[cur.num].size(); i++)
		{
			auto next = tree[cur.num][i];
			if (!check[next.num])
			{
				dist[next.num] = dist[cur.num] + next.weight;
				q.push(next);
				check[next.num] = true;
			}
		}
	}
}