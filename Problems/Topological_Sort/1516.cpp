#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MAXN 501

using namespace std;

struct Node
{
	int time;
	bool check = false;
	vector<Node*> before;
	vector<Node*> next;
}node[MAXN];

int Search(Node* node)
{
	if (node->check || node->before.empty())
	{
		node->check = true;
		return node->time;
	}
	int initialTime = node->time;
	for (int i = 0; i < node->before.size(); i++)
	{
		node->time = max(Search(node->before[i]) + initialTime, node->time);
	}
	node->check = true;
	return node->time;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int time;
		cin >> time;
		node[i].time = time;
	
		while (true)
		{
			int before;
			cin >> before;
			if (before < 0)
			{
				break;
			}

			node[i].before.push_back(&node[before]);
			node[before].next.push_back(&node[i]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (!node[i].before.empty())
		{
			node[i].time = Search(&node[i]);
		}
		else
		{
			node[i].check = true;
		}
		cout << node[i].time << "\n";
	}
	
	return 0;
}