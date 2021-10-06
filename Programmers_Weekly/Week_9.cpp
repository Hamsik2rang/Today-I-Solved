#include <iostream>
#include <vector>
#include <string>

#define MAXE 101

using namespace std;

int dfs(const vector<vector<int>>& graph, int cur, const int except, bool check[])
{
	check[cur] = true;
	int count = 1;
	for (int i = 0; i < graph[cur].size(); i++)
	{
		auto next = graph[cur][i];
		if (next != except && !check[next])
		{
			count += dfs(graph, next, except, check);
		}
	}

	return count;
}

int solution(int n, vector<vector<int>> wires)
{
	int answer = -1;

	vector<vector<int>> graph(n + 1);

	for (const auto& elem : wires)
	{
		graph[elem[0]].push_back(elem[1]);
		graph[elem[1]].push_back(elem[0]);
	}

	for (const auto& elem : wires)
	{
		bool check[2][MAXE]{ false };
		auto result = abs(dfs(graph, elem[0], elem[1], check[0]) - dfs(graph, elem[1], elem[0], check[1]));
		answer = (answer < 0 || answer > result) ? result : answer;
	}

	return answer;
}

int main(void)
{
	freopen("input3.txt", "r", stdin);
	int n;
	cin >> n;
	vector<vector<int>> wires(n - 1);

	for (int i = 0; i < n - 1; i++)
	{
		int w1, w2;
		cin >> w1 >> w2;
		wires[i].push_back(w1);
		wires[i].push_back(w2);
	}

	cout << solution(n, wires) << endl;

	return 0;
}