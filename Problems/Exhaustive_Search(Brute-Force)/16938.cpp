#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> problem;
vector<int> selected;
// num of problems / minimum difficulty / maximum difficulty / gap of difficulty
int n, l, r, x;
int answer;

bool promise()
{
	if (selected.back() - selected.front() < x)
	{
		return false;
	}

	int sum = std::accumulate(selected.begin(), selected.end(), 0);
	if (sum < l || sum > r)
	{
		return false;
	}

	return true;
}

void solution(int index)
{
	if (selected.size() >= 2)
	{
		if (promise())
		{
			answer++;
		}

		if (selected.size() == problem.size())
		{
			return;
		}
	}

	for (int i = index; i < problem.size(); i++)
	{
		selected.push_back(problem[i]);
		solution(i + 1);
		selected.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> l >> r >> x;

	for (int i = 0; i < n; i++)
	{
		int d;
		cin >> d;
		problem.push_back(d);
	}

	sort(problem.begin(), problem.end());
	solution(0);

	cout << answer;

	return 0;
}