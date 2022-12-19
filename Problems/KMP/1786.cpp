#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> skipTable;
vector<int> answer;
string t;
string p;

void SetSkipTable()
{
	int prefix = 0;
	for (int i = 1, len = p.length(); i < len; i++)
	{
		while (prefix > 0 && p[i] != p[prefix])
		{
			prefix = skipTable[prefix - 1];
		}
		if (p[prefix] == p[i])
		{
			skipTable[i] = ++prefix;
		}
	}
}

void Kmp()
{
	int pat = 0, txt = 0;
	while (pat < p.length() && txt < t.length())
	{
		if (p[pat] == t[txt])
		{
			pat++;
			txt++;
		}
		else if (pat == 0)
		{
			txt++;
		}
		else
		{
			pat = skipTable[pat - 1];
		}

		if (pat == p.length())
		{
			answer.push_back(txt - pat + 1);
			pat = skipTable[pat - 1];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "r", stdin);

	getline(cin, t);
	getline(cin, p);

	skipTable.assign(p.length(), 0);
	SetSkipTable();

	Kmp();

	cout << answer.size() << "\n";
	for (auto e : answer)
	{
		cout << e << " ";
	}

	return 0;
}