#include <string>
#include <vector>

using namespace std;

int GetDigit(int x)
{
    int res = 0;
    while (x > 0)
    {
        x /= 10;
        res++;
    }
    return res;
}

int solution(string s)
{
    int answer = s.length();

    for (int i = 1; i <= s.length() / 2; i++)
    {
		int ptr = 0;
		int next = ptr;
		int len = 0;
        while (ptr + i <= s.length())
        {
            auto cur = s.substr(ptr, i);
            while (next + i <= s.length() && cur == s.substr(next, i))
            {
                next += i;
            }
           
            if ((next - ptr) / i > 1)
            {
                len += GetDigit((next - ptr) / i);
            }
            len += i;
            ptr = next;
        }
        len += s.length() - ptr;
        answer = min(answer, len);
    }

    return answer;
}