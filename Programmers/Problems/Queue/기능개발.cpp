#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<pair<int, int>> q;

    for (int i = 0; i < progresses.size(); i++)
    {
        q.push(make_pair(progresses[i], speeds[i]));
    }
    int time = 0;
    while (!q.empty())
    {
        time++;
        int deploy = 0;
        while (!q.empty() && q.front().first + q.front().second * time >= 100)
        {
            q.pop();
            deploy++;
        }
        if (deploy)
        {
            answer.push_back(deploy);
        }
    }
    
    return answer;
}
int main()
{
    auto res = solution({ 95, 90, 99, 99, 80, 99 }, { 1,1,1,1,1,1 });
    for (auto e : res)
    {
        cout << e << " ";
    }

}