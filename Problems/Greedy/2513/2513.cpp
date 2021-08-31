#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, S;

struct PickUpInfo
{
	int pos;
	int student;
};

bool compare(PickUpInfo d1, PickUpInfo d2)
{
	return abs(d1.pos - S) < abs(d2.pos - S);
}

int main()
{
	scanf("%d %d %d", &N, &K, &S);

	int64_t result = 0;
	vector<PickUpInfo> apartment[2];

	for (int i = 0; i < N; i++)
	{
		int pos, student;
		scanf("%d %d", &pos, &student);
		if (pos < S)
			apartment[0].push_back({ pos, student });
		else
			apartment[1].push_back({ pos, student });
	}

	sort(apartment[0].begin(), apartment[0].end(), compare);
	sort(apartment[1].begin(), apartment[1].end(), compare);

	for (int i = 0; i < 2; i++)
	{
		while (apartment[i].size())
		{
			int cur = 0;
			while (apartment[i].size())
			{
				result += abs(apartment[i].back().pos - S) * 2 * (apartment[i].back().student / K);
				apartment[i].back().student %= K;
				if (!apartment[i].back().student) 
				{
					apartment[i].pop_back();
				}
				else
				{
					break;
				}
			}
			if (!apartment[i].size()) break;

			result += abs(apartment[i].back().pos - S) * 2;

			while (cur < K && apartment[i].size())
			{
				cur += apartment[i].back().student;
				if (cur > K)
				{
					apartment[i].back().student = cur - K;
				}
				else 
				{
					apartment[i].pop_back();
				}
			}
		}
	}
	cout << result << "\n";

	return 0;
}