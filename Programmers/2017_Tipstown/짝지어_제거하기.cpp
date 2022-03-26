#include <iostream>
#include <stack>

using namespace std;

int solution(string s)
{
	int answer = 0;
    stack<char> st;
    for (const auto& c : s)
    {
        if (st.empty())
        {
            st.push(c);
            continue;
        }
        if (st.top() == c)
        {
            st.pop();
        }
        else
        {
            st.push(c);
        }
    }
    if (st.empty())
    {
        answer = 1;
    }
    return answer;
}