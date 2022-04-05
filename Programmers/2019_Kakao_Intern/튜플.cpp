#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

bool compare(vector<int>& l, vector<int>& r)
{
    return l.size() < r.size();
}

bool check[100001];

vector<int> solution(string s)
{
    vector<int> answer;
    s.pop_back();
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9' || s[i] == '}')
        {
            continue;
        }
        else
        {
            s[i] = ' ';
        }
    }
    vector<vector<int>> tupleSet;
	vector<int> iv;
    stringstream ss(s);
    
    while (!ss.eof())
    {
        string temp;    
        ss >> temp;
        if (temp[temp.length() - 1] == '}')
        {
            temp.pop_back();
            iv.push_back(stoi(temp));
            tupleSet.push_back(iv);
            iv.clear();
        }
        else
        {
            iv.push_back(stoi(temp));
        }
    }
    
    sort(tupleSet.begin(), tupleSet.end(), compare);
    memset(check, 0, sizeof(check));
    for (int i = 0; i < tupleSet.size(); i++)
    {
        for (int j = 0; j < tupleSet[i].size(); j++)
        {
            if (!check[tupleSet[i][j]])
            {
                answer.push_back(tupleSet[i][j]);
                check[tupleSet[i][j]] = true;
            }
        }
    }

    return answer;
}
