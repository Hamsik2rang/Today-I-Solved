#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <utility>

using namespace std;

bool check[101][101];
int maxr;
int maxc;

void bfs(int r, int c, const vector<vector<int>>& picture, vector<int>& area)
{
    static int dr[] = { -1, 0, 1, 0 };
    static int dc[] = { 0, -1, 0, 1 };

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));
    check[r][c] = true;
    int cnt = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];

            if (nr < 0 || nr >= maxr || nc < 0 || nc >= maxc)
            {
                continue;
            }

            if (picture[cur.first][cur.second] == picture[nr][nc] && !check[nr][nc])
            {
                check[nr][nc] = true;
                q.push(make_pair(nr, nc));
            }
        }
    }
    area.push_back(cnt);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture)
{
    memset(check, false, sizeof(check));
    maxr = m;
    maxc = n;
    vector<int> area;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (picture[i][j] && !check[i][j])
            {
                bfs(i, j, picture, area);
            }
        }
    }
    int number_of_area = area.size();
    int max_size_of_one_area = *max_element(area.begin(), area.end());

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main()
{
    solution(6, 4, { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3}});

    return 0;
}