#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unsigned int coin[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}

	unsigned int answer = 0;
	unsigned int index = n;
	while (0 < k && 0 <= index)
	{
		index--;
		if (coin[index] > k)
		{
			continue;
		}
		answer += k / coin[index];
		k %= coin[index];
	}
	cout << answer;

	return 0;
}