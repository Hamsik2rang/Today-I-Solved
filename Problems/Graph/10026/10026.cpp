#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#define MAXN 101

using namespace std;

struct Pos
{
	int row;
	int col;
};

char graph[MAXN][MAXN];
bool check[MAXN][MAXN];

int dx[4]{ 0, -1, 0, 1 };
int dy[4]{ -1, 0, 1, 0 };

void bfs(int row, int col, function<bool(int, int, char)> promise);
bool checkForBlind(int row, int col, char cur);
bool checkForNormal(int row, int col, char cur);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		string row;
		cin >> row;
		
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = row[j - 1];
		}
	}

	int normal = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!check[i][j])
			{
				bfs(i, j, checkForNormal);
				normal++;
			}
		}
	}
	cout << normal << " ";

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			check[i][j] = false;
		}
	}

	int blindness = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!check[i][j])
			{
				bfs(i, j, checkForBlind);
				blindness++;
			}
		}
	}
	cout << blindness;

	return 0;
}

void bfs(int row, int col, function<bool(int, int, char)> promise)
{
	queue<Pos> q;
	q.push({ row, col });
	check[row][col] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.row + dy[i];
			int nx = cur.col + dx[i];
			if (promise(ny, nx, graph[cur.row][cur.col]))
			{
				q.push({ ny,nx });
				check[ny][nx] = true;
			}
		}
	}
}

bool checkForBlind(int row, int col, char cur)
{
	if (row < 1 || row >= MAXN || col < 1 || col >= MAXN)
	{
		return false;
	}
	if (check[row][col])
	{
		return false;
	}

	switch (graph[row][col])
	{
	case 'R':
	case 'G':
		if (cur == 'R' || cur == 'G')
		{
			return true;
		}
		break;
	case 'B':
		if (cur == 'B')
		{
			return true;
		}
		break;
	default:
		break;
	}

	return false;
}

bool checkForNormal(int row, int col, char cur)
{
	if (row < 1 || row >= MAXN || col < 1 || col >= MAXN)
	{
		return false;
	}
	if (check[row][col])
	{
		return false;
	}

	if (cur == graph[row][col])
	{
		return true;
	}

	return false;
}