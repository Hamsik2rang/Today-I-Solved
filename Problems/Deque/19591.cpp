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
		// ������ ���԰ų� �����ڰ� �����ؼ� ���� ���(ex. 3 * -4)
		if (wasOperator || !isOperator)
		{
			// ������ �ݵ�� ������ �� ���̰� 
			// ���� �Է°� ���� �Է��� ���ļ� ���� ���� �ϳ��� ������ �����̹Ƿ� 
			// �ϴ� �ǿ����� ���ڿ��� �߰��մϴ�.
			operandStr += expression[i];
			// �̹��� ����'-' ��ȣ�� ������ ��Ÿ���� ��ȣ�̹Ƿ� �����ڷ� ������� �ʽ��ϴ�.
			wasOperator = false;
		}
		// �����ڰ� ���� ���
		// ������ ���� �����ڸ� �߰��� �ְ� 
		// ���ݱ��� ���� ���� ���ڿ��� ���� ������ ��ȯ�� �ǿ����� ���� �߰��� �ݴϴ�.
		else
		{
			wasOperator = true;
			op.push_back(expression[i]);
			operand.push_back(stoll(operandStr));
			operandStr = "";
		}
	}
	// �ݺ����� ������ ��ó ���� ���� ���� ���ڿ��� ���� ��ȯ�� ���� �߰��մϴ�.
	operand.push_back(stoll(operandStr));

	// ��� �����ڸ� ����� �� ����(��� ����� ��ĥ ������) �ݺ��մϴ�.
	while (!op.empty())
	{
		// ������ �켱���� - 0: ���� / -1: lvalue�� �켱 / 1: rvalue�� �켱 
		auto order = OperationOrder(op.front(), op.back());
		// ������ ������ �켱������ ���� ���, ������ ���� �ڿ��� �����ڸ� ������
		// �ǿ����� ���� �ڿ��� �ǿ����� �ΰ��� ���� ���� ��
		// ����� �ǿ����� ���� �߰��մϴ�.
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
		// ������ �켱������ ������ ���
		// �� �ʿ��� �����ڿ� �ǿ����ڸ� ���� ������ �غ� ��
		// �� �� ����� �� ū (���ٸ� ������) �������� �����մϴ�.
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
		// ���� �����ڰ� �켱������ ���� ���
		// ���ʿ��� �ǿ����ڵ�� �����ڸ� ���� ���� �� 
		// ����� �ǿ����� ���� �տ� �߰��մϴ�.
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