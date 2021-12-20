#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int m;
		int printCount = 1;
		cin >> m;
		priority_queue<int, vector<int>, less<int>> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;

		cout << m / 2 + 1 << "\n";

		int first, second;
		cin >> first;
		if (m == 1)
		{
			cout << first << "\n";
			continue;
		}
		cout << first << " ";
		cin >> second;

		maxHeap.push(first > second ? second : first);
		minHeap.push(first > second ? first : second);

		for (int i = 3; i <= m; i++)
		{
			int input;
			cin >> input;

			if (input < minHeap.top())
			{
				maxHeap.push(input);
			}
			else
			{
				minHeap.push(input);
			}

			// print
			if (i & 1)
			{
				if (minHeap.size() > maxHeap.size())
				{
					cout << minHeap.top();
				}
				else
				{
					cout << maxHeap.top();
				}
			
				printCount++;
				if (printCount < 10)
				{
					cout << " ";
				}
				else
				{
					cout << "\n";
					printCount %= 10;
				}
			}

			while (maxHeap.size() > minHeap.size() + 1)
			{
				int temp = maxHeap.top();
				maxHeap.pop();
				minHeap.push(temp);
			}

			while (minHeap.size() > maxHeap.size() + 1)
			{
				int temp = minHeap.top();
				minHeap.pop();
				maxHeap.push(temp);
			}
		}
		cout << "\n";
	}

	return 0;
}