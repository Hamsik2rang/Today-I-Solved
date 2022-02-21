#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void calculate(std::string& answer, int avg)
{
    if (avg >= 90)
    {
        answer += "A";
    }
    else if (avg >= 80)
    {
        answer += "B";
    }
    else if (avg >= 70)
    {
        answer += "C";
    }
    else if (avg >= 50)
    {
        answer += "D";
    }
    else
    {
        answer += "F";
    }
}

string solution(vector<vector<int>> scores)
{
    string answer = "";

    vector<vector<int>> transpose(scores.size(), vector<int>(scores.size()));

    for (int row = 0; row < scores.size(); row++)
    {
        for (int col = 0; col < scores[row].size(); col++)
        {
            transpose[col][row] = scores[row][col];
        }
    }

    for (int i = 0; i < transpose.size(); i++)
    {
        int size = transpose[i].size();
        bool isUnique = true;
        bool isMaxOrMin = false;
        if (*max_element(transpose[i].begin(), transpose[i].end()) == transpose[i][i] || *min_element(transpose[i].begin(), transpose[i].end()) == transpose[i][i])
        {
            isMaxOrMin = true;
            for (int j = 0; j < transpose[i].size(); j++)
            {
                if (i == j)
                    continue;
                if (transpose[i][j] == transpose[i][i])
                {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique)
            {
                size--;
            }
        }

		int avg = accumulate(transpose[i].begin(), transpose[i].end(), (isMaxOrMin && isUnique ? -transpose[i][i] : 0)) / size;
        calculate(answer, avg);
    }

    return answer;
}