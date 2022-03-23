#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

bool check[8];

bool Promising(string s, const vector<string>& data)
{
    for (const auto& r : data)
    {
        int fromIdx = s.find(r[0]);
        int toIdx = s.find(r[2]);
		int dist = abs(fromIdx - toIdx) - 1;
        int condition = r[4] - '0';

        switch (r[3])
        {
        case '=':
            if (dist != condition)
            {
                return false;
            }
            break;
        case '<':
            if (dist >= condition)
            {
                return false;
            }
            break;
        case '>':
            if (dist <= condition)
            {
                return false;
            }
            break;
        default:
            return false;
        }
    }
    return true;
}

void Set(string s,const vector<char>& friends, const vector<string>& data, int& answer)
{
    if (s.length() == 8)
    {
        if (Promising(s, data))
        {
            answer++;
        }
        return;
    }

    for (int i = 0; i < friends.size(); i++)
    {
        if (check[i])
        {
            continue;
        }
        check[i] = true;
        s.push_back(friends[i]);
		Set(s, friends, data, answer);
        s.pop_back();
        check[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    int answer = 0;
    vector<char> friends({ 'A','C','F','J','M', 'N', 'R', 'T' });
    memset(check, false, sizeof(check));

	Set("", friends, data, answer);

    return answer;
}