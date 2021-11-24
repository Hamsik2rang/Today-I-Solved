#include <iostream>

using namespace std;

int stk[100000];
int top{ 0 };

int main()
{
	int k;
	cin >> k;

	for (int i = 0; i < k; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			top--;
		}
		else
		{
			stk[top++] = temp;
		}
	}
	uint64_t answer{ 0 };
	for (int i = 0; i < top; i++)
	{
		answer += stk[i];
	}
	cout << answer << endl;

	return 0;
}