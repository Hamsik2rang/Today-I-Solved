#include string
#include vector
#include unordered_map

using namespace std;

string solution(vectorstring participant, vectorstring completion) 
{
    string answer = ;
    unordered_mapstring, int map;
    for(const auto& e  completion)
    {
        map[e]++;
    }
    
    for(const auto & e  participant)
    {
        if(!map[e])
        {
            answer = e;
            break;
        }
        map[e]--;
    }
    
    return answer;
}