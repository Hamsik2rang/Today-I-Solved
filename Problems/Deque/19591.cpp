#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int64_t Operation(const int64_t& lvalue, const char& op, const int64_t& rvalue)
{
	int64_t result = 0ull;
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
		result = lvalue / rvalue;
		break;
	}

	return result;
}

bool IsOperator(const char& c)
{
	switch (c)
	{
	case '+':
	case '-':
	case '/':
	case '*':
		return true;
	default:;
	}
	return false;
}

int OperationOrder(const char& lhs, const char& rhs)
{
	if (((lhs == '*' || lhs == '/') && (rhs == '*' || rhs == '/')) || ((lhs == '+' || lhs == '-') && (rhs == '+' || rhs == '-')))
	{
		return 0;
	}
	else if (((lhs == '*' || lhs == '/') && (rhs == '+' || rhs == '-')))
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	deque<int64_t> operand;
	deque<char> op;
	string operandStr = "";
	string expression;
	bool wasOperator = true;
	cin >> expression;

	for (int i = 0; i < expression.length(); i++)
	{
		bool isOperator = IsOperator(expression[i]);
		// 정수가 들어왔거나 연산자가 연속해서 들어온 경우(ex. 3 * -4)
		if (wasOperator || !isOperator)
		{
			// 다음에 반드시 정수가 올 것이고 
			// 현재 입력과 다음 입력이 합쳐서 음수 정수 하나를 형성할 예정이므로 
			// 일단 피연산자 문자열에 추가합니다.
			operandStr += expression[i];
			// 이번에 들어온'-' 기호는 음수를 나타내는 기호이므로 연산자로 취급하지 않습니다.
			wasOperator = false;
		}
		// 연산자가 들어온 경우
		// 연산자 덱에 연산자를 추가해 주고 
		// 지금까지 쌓인 정수 문자열을 실제 정수로 변환해 피연산자 덱에 추가해 줍니다.
		else
		{
			wasOperator = true;
			op.push_back(expression[i]);
			operand.push_back(stoll(operandStr));
			operandStr = "";
		}
	}
	// 반복문이 끝나고 미처 들어가지 못한 정수 문자열을 마저 변환해 덱에 추가합니다.
	operand.push_back(stoll(operandStr));

	// 모든 연산자를 사용할 때 까지(모든 계산을 마칠 때까지) 반복합니다.
	while (!op.empty())
	{
		// 연산자 우선순위 - 0: 동등 / -1: lvalue가 우선 / 1: rvalue가 우선 
		auto order = OperationOrder(op.front(), op.back());
		// 오른쪽 연산자 우선순위가 높은 경우, 연산자 덱의 뒤에서 연산자를 꺼내고
		// 피연산자 덱의 뒤에서 피연산자 두개를 꺼내 연산 후
		// 결과를 피연산자 덱에 추가합니다.
		if (order == 1)
		{
			auto rvalue = operand.back();
			operand.pop_back();
			char oprator = op.back();
			op.pop_back();
			auto lvalue = operand.back();
			operand.pop_back();

			operand.push_back(Operation(lvalue, oprator, rvalue));
		}
		// 연산자 우선순위가 동등한 경우
		// 양 쪽에서 연산자와 피연산자를 꺼내 연산을 해본 후
		// 둘 중 결과가 더 큰 (같다면 왼쪽을) 방향으로 진행합니다.
		else if (order == 0)
		{
			auto rvalue = operand.back();
			operand.pop_back();
			char oprator = op.back();
			op.pop_back();
			auto lvalue = operand.back();
			operand.pop_back();

			operand.push_back(lvalue);
			operand.push_back(rvalue);
			op.push_back(oprator);

			auto backResult = Operation(lvalue, oprator, rvalue);

			lvalue = operand.front();
			operand.pop_front();
			oprator = op.front();
			op.pop_front();
			rvalue = operand.front();
			operand.pop_front();

			operand.push_front(rvalue);
			operand.push_front(lvalue);
			op.push_front(oprator);

			auto frontResult = Operation(lvalue, oprator, rvalue);

			if (backResult > frontResult)
			{
				operand.pop_back();
				operand.pop_back();
				op.pop_back();
				operand.push_back(backResult);
			}
			else
			{
				operand.pop_front();
				operand.pop_front();
				op.pop_front();
				operand.push_front(frontResult);
			}
		}
		// 왼쪽 연산자가 우선순위가 높은 경우
		// 왼쪽에서 피연산자들과 연산자를 꺼내 연산 후 
		// 결과를 피연산자 덱의 앞에 추가합니다.
		else
		{
			auto lvalue = operand.front();
			operand.pop_front();
			char oprator = op.front();
			op.pop_front();
			auto rvalue = operand.front();
			operand.pop_front();

			operand.push_front(Operation(lvalue, oprator, rvalue));
		}
	}
	cout << operand.front();

	return 0;
}