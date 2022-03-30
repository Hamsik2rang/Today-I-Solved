#include <string>
#include <vector>

using namespace std;

bool isProper(string p)
{
    int cnt = 0;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt < 0)
        {
            return false;
        }
    }
    return true;
}

void flip(string& p)
{
    for (auto& e : p)
    {
        if (e == '(')
        {
            e = ')';
        }
        else
        {
            e = '(';
        }
    }
}

string solution(string p)
{
    string answer = "";
    if (p == "")
    {
        return p;
    }
    int cnt = 0;
    string u, v;
    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '(')
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (!cnt)
        {
			u = p.substr(0, i + 1);
            v = p.substr(i + 1);
            break;
        }
    }
    if (isProper(u))
    {
        answer =  u + solution(v);
    }
    else
    {
        string s = "(" + solution(v) + ")";
        u.pop_back();
        u = u.substr(1);
        flip(u);
        answer = s + u;
    }

    return answer;
}

int main()
{
    solution(")(");

    return 0;
}