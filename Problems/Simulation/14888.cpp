#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int oprand[4];
int answer;

enum OPCODE { SUM = 0, SUB, MUL, DIV };

int getMax(int l, int r)
{
	return l < r ? r : l;
}

int getMin(int l, int r)
{
	return l < r ? l : r;
}

int calculate(int l, int r, int oprand)
{
	switch (oprand)
	{
	case SUM:
		return l + r;
	case SUB:
		return l - r;
	case MUL:
		return l * r;
	case DIV:
		return l / r;
	}
}

int solution(int index, int cur, const int start, int(*compare)(int, int))
{
	if (index == v.size())
	{
		return cur;
	}
	int answer = start;
	for (int i = 0; i < 4; i++)
	{
		if (!oprand[i])
			continue;
		oprand[i]--;
		int result = solution(index + 1, calculate(cur, v[index], i), start, compare);
		answer = compare(answer, result);
		oprand[i]++;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
		cin >> oprand[i];

	int answer = solution(1, v[0],-1000000001, getMax);
	cout << answer<<"\n";
	answer = solution(1, v[0], 1000000001, getMin);
	cout << answer;

	return 0;
}