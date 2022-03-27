#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

bool IsAlpha(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int solution(string str1, string str2)
{
    int answer = 0;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;

    set<string> set1;
    set<string> set2;

	for (int i = 0; i < str1.length() - 1; i++)
    {
		str1[i] = toupper(str1[i]);
		str1[i + 1] = toupper(str1[i + 1]);

        if (IsAlpha(str1[i]) && IsAlpha(str1[i + 1]))
        {
            string key = str1.substr(i, 2);
            m1[key]++;
            set1.insert(key);
        }
    }

    for (int i = 0; i < str2.length() - 1; i++)
    {
        str2[i] = toupper(str2[i]);
        str2[i + 1] = toupper(str2[i + 1]);

        if (IsAlpha(str2[i]) && IsAlpha(str2[i + 1]))
        {
            string key = str2.substr(i, 2);
            m2[key]++;
            set2.insert(key);
        }
    }

    set<string> is;
    set<string> un;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(is, is.begin()));
    set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(un, un.begin()));

    int num = 0;
    for (const auto& e : is)
    {
        if (m2[e] == 0)
        {
            num += m1[e];
        }
        else if (m1[e] == 0)
        {
            num += m2[e];
        }
        else
        {
            num += min(m1[e], m2[e]);
        }
    }

    int denom = 0;
    for (const auto& e : un)
    {
        if (m2[e] == 0)
        {
            denom += m1[e];
        }
        else if (m1[e] == 0)
        {
            denom += m2[e];
        }
        else
        {
            denom += max(m1[e], m2[e]);
        }
    }
    if (num == 0 && denom == 0)
    {
        return 65536;
    }
    float result = (float)num / (float)denom * 65536.0f;
    answer = (int)result;

    return answer;
}