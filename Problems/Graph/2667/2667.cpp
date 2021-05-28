#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool check[25][25];
int graph[25][25];
int dx[]{ -1,1,0,0 };
int dy[]{ 0,0,-1,1 };

int BFS(int r, int c, int maxR, int maxC)
{
	int count = 1;
	queue<pair<int, int>> q;
	check[r][c] = true;
	q.push(make_pair(r, c));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int nextX = x + dx[i];
			int nextY = y + dy[i];

			if (nextX >= 0 && nextX < maxR && nextY >= 0 && nextY < maxC)
			{
				if (graph[nextX][nextY] && !check[nextX][nextY])
				{
					check[nextX][nextY] = true;
					q.push(make_pair(nextX, nextY));
					count++;
				}
			}
		}
		q.pop();
	}

	return count;
}

int main()
{
	int n;
	vector<int> count;
	int complex = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = s[j] - '0';
		}
	}

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (graph[r][c] && !check[r][c])
			{
				count.push_back(BFS(r, c, n, n));
				complex++;
			}
		}
	}
	sort(count.begin(), count.end());

	cout << complex << endl;
	for (const auto& elem : count)
	{
		cout << elem << endl;
	}

	return 0;
}