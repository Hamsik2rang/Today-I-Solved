#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>

using namespace std;

int n, m;

int person[101];
int64_t dirty[101];
int64_t D[101][101][11];
vector<int> cleanDay;

int64_t solution(int index, int before, int count)
{
	if (index > n)
	{
		return 0;
	}

	int64_t& cur = D[index][before][count];

	if (cur >= 0)
	{
		return cur;
	}
	cur = ((dirty[index] - dirty[before + 1]) * person[index]);

	if (count > 0)
	{
		cur += ::min(solution(index + 1, index, count - 1), solution(index + 1, before, count));
	}
	else
	{
		cur += solution(index + 1, before, count);
	}

	return cur;
}

void countDay(int index, int before, int count)
{
	if (count == 0)
	{
		return;
	}

	if (D[index + 1][index][count - 1] <= D[index + 1][before][count])
	{
		cleanDay.push_back(index);
		countDay(index + 1, index, count - 1);
	}
	else
	{
		countDay(index + 1, before, count);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> person[i];
		dirty[i + 1] = dirty[i] + person[i];
	}
	memset(D, -1, sizeof(D));


	cout << solution(1, 0, m) << "\n";
	countDay(1, 0, m);
	for (const auto& e : cleanDay)
	{
		cout << e << " ";
	}

	return 0;
}