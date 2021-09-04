#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int num = 0;
	Node* parent = nullptr;
	vector<Node*> child;

	Node* get(int num)
	{
		this->num = num;

		return this;
	}
}memPool[100001], *node[100001];

int memPoolCnt = 0;

void changeParent(Node*, Node*);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int parent, child;
		cin >> parent >> child;
		if (child == 1)
		{
			parent ^= child;
			child ^= parent;
			parent ^= child;
		}
		if (!node[parent])
		{
			node[parent] = memPool[memPoolCnt++].get(parent);
		}
		if (!node[child])
		{
			node[child] = memPool[memPoolCnt++].get(child);
		}
		changeParent(node[child], node[parent]);
		node[parent]->child.push_back(node[child]);
	}
	changeParent(node[1], nullptr);

	for (int i = 2; i <= n; i++)
	{
		cout << node[i]->parent->num << "\n";
	}

	return 0;
}

void changeParent(Node* cur, Node* last)
{
	if (cur->parent)
	{
		changeParent(cur->parent, cur);
	}
	cur->child.push_back(cur->parent);
	cur->parent = last;
}