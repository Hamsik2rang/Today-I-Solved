#include <iostream>

using namespace std;

int set[20];
bool hasCalculated;
int answer;

void solution(int start, int n, int s, int sum = 0)
{
	if (sum == s && hasCalculated)
	{
		answer++;
	}
	hasCalculated = true;

	for (int i = start; i < n; i++)
		solution(i + 1, n, s, sum + set[i]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> set[i];
	}

	solution(0, n, s);

	cout << answer;

	return 0;
}