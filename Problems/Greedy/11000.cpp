#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

struct compare
{
	bool operator()(pair<int, int>& l, pair<int, int>& r)
	{
		if (l.second == r.second)
		{
			return l.first > r.first;
		}
		return l.second > r.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		q.push(make_pair(start, end));
	}
	int max = 0;
	while(!q.empty())
	{
		int start = q.top().first;
		int end = q.top().second;
		
		while (!pq.empty() && pq.top().second <= start)
		{
			pq.pop();
		}
		pq.push(q.top());
		q.pop();
		max = pq.size() > max ? pq.size() : max;
	}
	cout << max;

	return 0;
}