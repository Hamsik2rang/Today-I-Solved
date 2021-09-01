#define _CRT_SECURE_NO_WARNINGS
#define MAXN 17
#define INF 0x6FFFFFFF

#include <iostream>
#include <cstring>

using namespace std;

int N, W[MAXN][MAXN];
int D[MAXN][(1 << 16)];
int find(int x, const int dest, int check);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	//freopen("input.txt", "r", stdin);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> W[i][j];
		}
	}
	memset(D, -1, sizeof(D));
	// Departure vertex 1, should return to vertex 1,and set right-first of check bitmask
	int answer = find(1, 1, 1);
	cout << answer << "\n";

	return 0;
}

int find(int x, const int dest, int check)
{
	// if already record result of visit of current check state, return that.
	if (D[x][check] != -1)
	{
		return D[x][check];
	}

	// if visited all vertices
	if (check == (1 << N) - 1)
	{
		// if can't return to departure vertex
		if (!W[x][dest])
		{
			return INF;
		}
		else
		{
			return W[x][dest];
		}
	}
	int answer = INF;
	for (int i = 1; i <= N; i++)
	{
		if (i == x)
		{
			continue;
		}
		// ignore already visited vertex
		if (!W[x][i] || (check & (1 << (i - 1))))
		{
			continue;
		}
		// visit all vertex that not visited yet
		auto nextCheck = check | (1 << (i - 1));
		int result = find(i, dest, nextCheck) + W[x][i];
		answer = answer > result ? result : answer;
	}
	// record minimum value of visiting adjacency vertices
	D[x][check] = answer;

	return D[x][check];
}