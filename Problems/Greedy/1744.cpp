#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	priority_queue<int> p;
	priority_queue<int, vector<int>, greater<>> znn;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		temp > 0 ? p.push(temp) : znn.push(temp);
	}
	vector<int> v(n);
	
	while (!p.empty())
	{
		if (p.size() == 1)
		{
			v.push_back(p.top());
			break;
		}
		int l = p.top();
		p.pop();
		int r = p.top();
		p.pop();
		(l * r >= l + r) ? v.push_back(l * r) : (v.push_back(l), v.push_back(r));
	}
	while (!znn.empty())
	{
		if (znn.size() == 1)
		{
			v.push_back(znn.top());
			break;
		}
		int l = znn.top();
		znn.pop();
		int r = znn.top();
		znn.pop();
		(l * r >= l + r) ? v.push_back(l * r) : (v.push_back(l), v.push_back(r));
	}
	cout << accumulate(v.begin(), v.end(), 0);

	return 0;
}