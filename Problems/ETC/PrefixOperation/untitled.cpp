#include <iostream>
#include <vector>
#include <string>
#include <stack>

int operation(const int& lvalue, const char& op, const int& rvalue, bool& isZeroDivided)
{
	int result = 0;
	switch (op)
	{
	case '+':
		result = lvalue + rvalue;
		break;
	case '-':
		result = lvalue - rvalue;
		break;
	case '*':
		result = lvalue * rvalue;
		break;
	case '/':
		if (rvalue == 0)
		{
			isZeroDivided = true;
			return 0;
		}
		result = lvalue / rvalue;
		break;
	default:
		break;
	}

	return result;
}

std::string solution(const std::string& expression)
{
	std::string answer;
	std::stack<char> st;
	std::stack<int> operand;
	std::string prefix = "";
	bool isZeroDivided = false;
	bool isMinus = false;

	for (const auto& c : expression)
	{
		if (c >= '0' && c <= '9')
		{
			prefix += c;
		}
		else if (c == '+' || c == '-')
		{
			while (!st.empty())
			{
				prefix += st.top();
				st.pop();
			}
			st.push(c);
		}
		else
		{
			while (!st.empty() && st.top() != '+' && st.top() != '-')
			{
				prefix += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while (!st.empty())
	{
		prefix += st.top();
		st.pop();
	}

	for (int i = 0; i < prefix.length(); i++)
	{
		if (prefix[i] >= '0' && prefix[i] <= '9')
		{
			operand.push(prefix[i] - '0');
		}
		else
		{
			auto rvalue = operand.top();
			operand.pop();
			auto lvalue = operand.top();
			operand.pop();
			operand.push(operation(lvalue, prefix[i], rvalue, isZeroDivided));

			if (isZeroDivided)
			{
				return "Impossible";
			}
		}
	}
	answer = std::to_string(operand.top());
	return answer;
}

int main()
{
	std::string s = "3+4-2*5";

	std::cout << solution(s);

	return 0;
}