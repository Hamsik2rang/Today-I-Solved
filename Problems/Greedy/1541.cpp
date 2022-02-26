#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// It has least result when all plus operation are surrounded with barces.
// ex.
// a + b - c - d + e - f
// = (a + b) - c - (d + e) - f 
// = a + b - c - d - e - f
// That we can know is, all plus operator after first minus operator is converted to minus operator.

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	
	int left;
	char op;
	int right;
	cin >> left;
	bool flag = false;
	while ((cin >> op))
	{
		if (op == '\n')
		{
			break;
		}
		cin >> right;
		if (op == '-')
		{
			flag = true;
		}
		if (flag)
		{
			left -= right;
		}
		else
		{
			left += right;
		}
	}
	cout << left;

	return 0;
}