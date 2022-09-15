#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAXN 100001

struct Node
{
	bool isFinish{ false };
	Node* next[10]{ nullptr };
}nodePool[MAXN];

int nodeIndex = 0;

Node* Alloc()
{
	nodePool[nodeIndex].isFinish = false;
	for (int i = 0; i < 10; i++)
	{
		nodePool[nodeIndex].next[i] = nullptr;
	}
	return &nodePool[nodeIndex++];
}

bool exist;
Node* root;

void SetTrie(const string& s)
{
	auto cur = root;
	for (const auto& e : s)
	{
		int nextIndex = e - '0';
		if (!cur->next[nextIndex])
		{
			cur->next[nextIndex] = Alloc();
		}
		cur = cur->next[nextIndex];
	}
	cur->isFinish = true;
}

bool Solution(const string& s)
{
	auto cur = root;
	for (int i = 0; i < s.length(); i++)
	{
		int nextIndex = s[i] - '0';
		cur = cur->next[nextIndex];
		if (i != s.length() - 1 && cur->isFinish)
		{
			return false;
		}

	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n;
		cin >> n;

		exist = false;
		nodeIndex = 0;
		root = Alloc();
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			v.push_back(s);
			SetTrie(s);
		}
		bool exist = false;
		for (int i = 0; i < n; i++)
		{
			if (!Solution(v[i]))
			{
				exist = true;
			}
		}
		if (exist)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}

	return 0;
}