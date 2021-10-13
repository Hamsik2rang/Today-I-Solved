#define _CRT_SECURE_NO_WARNINGS
#define MAXN 51

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int parent[MAXN];
bool isWise[MAXN];

void makeSet(int v, bool wise)
{
    parent[v] = v;
    isWise[v] = wise;
}

int findSet(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    return findSet(parent[v]);
}

void unionSet(int u, int v)
{
	auto vPres = findSet(v);
	auto uPres = findSet(u);
    
    if (isWise[uPres])
    {
        parent[vPres] = uPres;
    }
    else
    {
		parent[uPres] = vPres;
    }
}

int main(int argc, char** argv)
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> party(m);
    int wiseCnt;
    cin >> wiseCnt;

    for (int i = 1; i < MAXN; i++)
    {
        makeSet(i, false);
    }

    for (int i = 0; i < wiseCnt; i++)
    {
        int man;
        cin >> man;
        isWise[man] = true;
    }

    for (int i = 0; i < m; i++)
    {
        int manCnt;
        cin >> manCnt;
        
        for (int j = 0; j < manCnt; j++)
        {
            int man;
            cin >> man;
            party[i].push_back(man);
        }
        for (int j = 1; j < manCnt; j++)
        {
            unionSet(party[i][0], party[i][j]);
        }
    }

    int answer = 0;
    for (int i = 0; i < party.size(); i++)
    {
        if (isWise[findSet(party[i][0])])
        {
            continue;
        }
        answer++;
    }
    cout << answer << endl;

    return 0;
}