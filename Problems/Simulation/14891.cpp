#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int k;
string gear[4] = { "" };
int gearIndex[4] = { 0 };
bool rotated[4];

void process(int index, int dir)
{
	dir *= -1;
	rotated[index] = true;
	if (index < 3 && !rotated[index + 1])
	{
		int l = (gearIndex[index] + 2) % 8;
		int r = (gearIndex[index + 1] - 2 + 8) % 8;
		if (gear[index][l] != gear[index + 1][r])
			process(index + 1, dir);
	}
	if (index > 0 && !rotated[index - 1])
	{
		int l = (gearIndex[index - 1] + 2) % 8;
		int r = (gearIndex[index] - 2 + 8) % 8;
		if (gear[index - 1][l] != gear[index][r])
			process(index - 1, dir);
	}
	
	gearIndex[index] = (gearIndex[index] + dir + 8) % 8;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 4; i++)
	{
		cin >> gear[i];
	}

	cin >> k;

	while (k--)
	{
		int num;
		int dir;
		cin >> num >> dir;
		memset(rotated, false, sizeof(bool) * 4);
		process(num - 1, dir);
	}
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		answer += ((gear[i][gearIndex[i]] - '0') << i);
	}
	cout << answer;

	return 0;
}