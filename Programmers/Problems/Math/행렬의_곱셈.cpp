#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;

    for (int i = 0; i < arr1.size(); i++)
    {
        vector<int> m;
        for (int j = 0; j < arr2[0].size(); j++)
        {
            int result = 0;
            for (int k = 0; k < arr2.size(); k++)
            {
                result += arr1[i][k] * arr2[k][j];
            }
            m.push_back(result);
        }
        answer.push_back(m);
    }

    return answer;
}