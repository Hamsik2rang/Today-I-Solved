#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
	vector<int> answer;

	vector<vector<int>> m(rows + 1, vector<int>(columns + 1));
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= columns; j++)
		{
			m[i][j] = (i - 1) * columns + j;
		}
	}

	for (const auto& elem : queries)
	{
		int sr = elem[0];
		int sc = elem[1];
		int er = elem[2];
		int ec = elem[3];

		int vertex[4] = { m[sr][sc], m[sr][ec],  m[er][ec], m[er][sc] };
		for (int x = ec; x > sc; x--)
		{
			m[sr][x] = m[sr][x - 1];
		}
		for (int y = er; y > sr; y--)
		{
			m[y][ec] = m[y - 1][ec];
		}
		for (int x = sc; x < ec; x++)
		{
			m[er][x] = m[er][x + 1];
		}
		for (int y = sr; y < er; y++)
		{
			m[y][sc] = m[y + 1][sc];
		}

		m[sr + 1][ec] = vertex[1];
		m[er][ec - 1] = vertex[2];
		m[er - 1][sc] = vertex[3];

		int min = 10001;
		for (int r = sr; r <= er; r++)
		{
			for (int c = sc; c <= ec; c++)
			{
				if ((r != sr && r != er) && (c != sc && c != ec))
				{
					continue;
				}
				if (m[r][c] < min)
				{
					min = m[r][c];
				}
			}
		}
		answer.push_back(min);
	}

	return answer;
}