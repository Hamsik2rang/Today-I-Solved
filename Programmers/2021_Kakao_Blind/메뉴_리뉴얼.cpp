#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> m;

void SetMenu(const string order, int index, string result, vector<int> course)
{
    if (order.length() == index)
    {
        for (int i = 0; i < course.size(); i++)
        {
            if (result.length() == course[i])
            {
                sort(result.begin(), result.end());
                m[result]++;
            }
        }
		return;
    }
    SetMenu(order, index + 1, result, course);
    result += order[index];
    SetMenu(order, index + 1, result, course);
}


vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++)
    {
        SetMenu(orders[i], 0, "", course);
    }

	vector<vector<pair<string, int>>> v(course.size());

    for (auto iter = m.begin(); iter != m.end(); iter++)
    {
        for (int i = 0; i < course.size(); i++)
        {
            if (iter->first.length() == course[i] && iter->second > 1)
            {
                v[i].push_back(make_pair(iter->first, iter->second));
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
		if (v[i].empty())
        {
            continue;
        }
        sort(v[i].begin(), v[i].end(), [](pair<string, int>& l, pair<string, int>& r)->bool {
            return l.second > r.second;
            });
        int maxCount = v[i][0].second;
        answer.push_back(v[i][0].first);
        for (int j = 1; j < v[i].size() &&  v[i][j].second == maxCount; j++)
        {
            answer.push_back(v[i][j].first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    auto answer = solution({ "XYZ", "XWY", "WXA" }, { 2,3,4 });

    for (const auto& e : answer)
    {
        cout << e << " ";
    }
}