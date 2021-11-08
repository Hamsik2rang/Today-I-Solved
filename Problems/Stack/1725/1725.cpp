#define MAXN 100002

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<long long> histogram(MAXN);
	stack<long long> st;
	for (int i = 1; i <= n; i++)
	{
		cin >> histogram[i];
	}

	st.push(0);
	long long answer = 0;
	for (int i = 1; i <= n + 1; i++)
	{
		while (!st.empty() && histogram[st.top()] > histogram[i])
		{
			long long index = st.top();
			st.pop();
			answer = max(answer, histogram[index] * (i - st.top() - 1));
		}
		st.push(i);
	}

	cout << answer << endl;

	return 0;
}