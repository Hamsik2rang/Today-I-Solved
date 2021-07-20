#include <iostream>
#include <vector>

#define MAX_NODE 51

using namespace std;

int dfs(const vector<vector<int>>& tree, int node, const int& del)
{
	if (node == del) return 0;
	int result = 0;
	for (int i = 0; i < tree[node].size(); i++)
	{
		result += dfs(tree, tree[node][i], del);
	}

	return result == 0 ? 1 : result;
}

int main()
{
	int n;
	int root = -1;
	cin >> n;
	vector<vector<int>> tree(MAX_NODE);

	for (int i = 0; i < n; i++)
	{
		int parent;
		cin >> parent;
		if (parent < 0)
			root = i;
		else
			tree[parent].push_back(i);
	}
	int del;
	cin >> del;

	cout << dfs(tree, root, del) << endl;

	return 0;
}