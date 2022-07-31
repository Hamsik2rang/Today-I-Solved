#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int, int>> piece;
int answer;
bool check[5][5];
bool visited[5][5];

int Search(int row, int col)
{
	static const int dr[]{ -1, 0, 1, 0 };
	static const int dc[]{ 0, -1, 0, 1 };

	visited[row][col] = true;
	int result = 1;
	for (int i = 0; i < 4; i++)
	{
		int nr = row + dr[i];
		int nc = col + dc[i];
		if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5 || !check[nr][nc] || visited[nr][nc])
		{
			continue;
		}
		result += Search(nr, nc);
	}
	return result;
}

bool Promise()
{
	int r, c;
	for (r = 0; r < 5; r++)
	{
		for (c = 0; c < 5; c++)
		{
			if (check[r][c])
			{
				goto lb_found;
			}
		}
	}
lb_found:
	memset(visited, false, sizeof(visited));
	return (Search(r, c) == piece.size());
}

void Find(int index, int dist)
{
	if (dist >= answer)
	{
		return;
	}

	if (index == piece.size())
	{
		if (Promise())
		{
			answer = answer > dist ? dist : answer;
		}
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (check[i][j])
			{
				continue;
			}

			check[i][j] = true;
			Find(index + 1, dist + abs(i - piece[index].first) + abs(j - piece[index].second));
			check[i][j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> s[i];
		for (int j = 0; j < 5; j++)
		{
			if (s[i][j] == '*')
			{
				piece.push_back(make_pair(i, j));
			}
		}
	}

	answer = 0x3fffffff;
	Find(0, 0);
	cout << answer << endl;

	return 0;
}