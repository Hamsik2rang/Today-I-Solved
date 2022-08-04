#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>

#include <fstream>

using namespace std;

#define MAXN 1001

inline bool isAlpha(char c)
{
	return c >= 'a' && c <= 'z';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	string s;
	while (cin >> s)
	{
		stack<int> stk;
		bool canPrint[MAXN]{};
		// 1. 여는 괄호 직전에 알파벳 또는 닫는 괄호가 존재했으면서 괄호 내에 +가 존재하는 경우 -> a(b+c) or (...)(b+c)
		// 2. 괄호 내에 +가 존재했으면서 닫는 괄호 직후에 문자 또는 여는 괄호가 존재하는 경우 -> (a+b)c or (a+b)(...)
		// 
		// 위 두 가지만 괄호를 보존하고 나머지는 거르면 됨
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				stk.push(i);
			}
			else if (s[i] == ')')
			{
				int left = stk.top();
				int right = i;
				bool isTherePlus = false;
				bool isThereInnerBracket = false;
				for (int j = left + 1; j < right - 1; j++)
				{
					if (isThereInnerBracket && s[j] != ')')
					{
						continue;
					}

					if (s[j] == '(' && canPrint[j])
					{
						isThereInnerBracket = true;
					}
					else if (s[j] == ')' && canPrint[j])
					{
						isThereInnerBracket = false;
					}
					if (s[j] == '+')
					{
						isTherePlus = true;
						break;
					}
				}

				if (isTherePlus &&
					((left > 0 && (isAlpha(s[left - 1]) || s[left - 1] == ')')) ||
						(right < s.length() - 1 && (isAlpha(s[right + 1]) || s[right + 1] == '('))))
				{
					canPrint[right] = canPrint[left] = true;
				}

				stk.pop();
			}
			else
			{
				canPrint[i] = true;
			}
		}

		string answer = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (canPrint[i])
			{
				answer.push_back(s[i]);
			}
		}
		cout << answer << "\n";
	}

	return 0;
}