#include <string>
#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, int s)
{
    vector<int> answer;
    if (s < n)
    {
        answer.push_back(-1);
        return answer;
    }
    int start = s / n;
    for (int i = 0; i < n; i++)
    {
        answer.push_back(start);
    }
    auto d = s - std::accumulate(answer.begin(), answer.end(), 0);
    int index = answer.size() - 1;
    while (d > 0)
    {
        d--;
        answer[index--]++;
        index = (index + answer.size()) % answer.size();
    }
    return answer;
}

int main()
{

    solution(2, 9);
}