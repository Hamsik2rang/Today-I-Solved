#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution(vector<int> v,  int least);

int d[8];
int m, n;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	sort(d, d + n);
	vector<int> v;
	solution(v, m);

	return 0;
}

void solution(vector<int> v,  int least)
{
	if (least <= 0)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << d[v[i]] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (find(v.begin(), v.end(), i) != v.end())
		{
			continue;
		}
		v.push_back(i);
		solution(v, least - 1);
		v.pop_back();
	}
}