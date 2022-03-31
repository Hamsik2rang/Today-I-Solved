#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;

inline int distance(int r1, int c1, int r2, int c2)
{
    return abs(r2 - r1) + abs(c2 - c1);
}

bool isViolated(vector<string> places, int r, int c, bool check[5][5])
{
    static int dr[]{ -1, 0, 1, 0 };
    static int dc[]{ 0, -1, 0, 1 };
    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    check[r][c] = true;
    bool hasFound = false;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5 || check[nr][nc])
            {
                continue;
            }
            check[nr][nc] = true;
            if (places[nr][nc] == 'X')
            {
                continue;
            }
            if (distance(r, c, nr, nc) > 2)
            {
                continue;
            }
            else
            {
                if (places[nr][nc] == 'O')
                {
                    q.push(make_pair(nr, nc));
                }
                else
                {
                    return true;
                }
            }
        }
    }

    return hasFound;
}

vector<int> solution(vector<vector<string>> places)
 {
    vector<int> answer;

    for (const auto& tc : places)
    {
        bool check[5][5]{ false };
        bool violate = false;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (tc[i][j] == 'P')
                {
                    violate = isViolated(tc, i, j, check);
                    if (violate)
                    {
                        goto lb_next;
                    }
                }
            }
        }
    lb_next:
        if (violate)
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(1);
        }
    }

    return answer;
}