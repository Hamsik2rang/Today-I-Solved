#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

using namespace std;

const int MAXN = 26 * 26 * 26;

struct Node
{
    string name = "";
    vector<pair<int, bool>> next;
}node[MAXN];
bool check[MAXN];
bool hasFound = false;
inline int getIndex(string s)
{
    int index = (s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A');
    return index;
}

void dfs(vector<string>& answer, int index, int answerSize)
{
    answer.push_back(node[index].name);
    if (answer.size() == answerSize)
    {
        hasFound = true;
        return;
    }

    for (int i = 0; i < node[index].next.size(); i++)
    {
        if (node[index].next[i].second)
        {
            continue;
        }
        node[index].next[i].second = true;
        dfs(answer, node[index].next[i].first, answerSize);
        if (hasFound)
        {
            return;
        }
        node[index].next[i].second = false;
    }
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets)
{
    vector<string> answer;
    for (int i = 0; i < tickets.size(); i++)
    {
        auto from = tickets[i][0];
        auto to = tickets[i][1];
        auto fromIdx = getIndex(from);
        auto toIdx = getIndex(to);
        node[fromIdx].name = from;
        node[toIdx].name = to;
        node[fromIdx].next.push_back(make_pair(toIdx, false));
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        auto index = getIndex(tickets[i][0]);
        sort(node[index].next.begin(), node[index].next.end(),
            [](const pair<int, bool>& l, const pair<int, bool>& r)->bool {
                return l.first <r.first;
            });
    }
	dfs(answer, getIndex("ICN"), tickets.size() + 1);
    return answer;
}