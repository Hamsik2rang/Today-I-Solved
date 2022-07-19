#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	priority_queue<uint64_t, vector<uint64_t>, greater<>> pq;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		uint64_t num;
		cin >> num;
		pq.push(num);
	}

	uint64_t answer = 0;
	while (pq.size() > 1)
	{
		auto first = pq.top();
		pq.pop();
		auto second = pq.top();
		pq.pop();

		answer += first + second;
		pq.push(first + second);
	}

	cout << answer;

	return 0;
}