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
	// 1번 정점에서 출발하며, 1번 정점으로 되돌아와야 하고 1번에서 시작하므로 방문 비트의 오른쪽에서 첫 번째(2^0) 비트 set, 출발 비용은 없으므로 0으로 호출
	int answer = find(1, 1, 1);
	cout << answer << "\n";

	return 0;
}

int find(int x, const int dest, int check)
{
	// 이미 현재 방문 상태에서의 탐색 결과가 메모되어 있다면 해당 값을 리턴
	if (D[x][check] != -1)
	{
		return D[x][check];
	}

	// 모든 정점을 방문했다면
	if (check == (1 << N) - 1)
	{
		// 출발 정점으로 돌아갈 수 없는 경우(인접하지 않은 경우)
		if (!W[x][dest])
		{
			return INF;
		}
		// 돌아갈 수 있는 경우
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
		// 방문한 정점은 무시
		if (!W[x][i] || (check & (1 << (i - 1))))
		{
			continue;
		}
		// 방문하지 않은 인접한 모든 정점을 방문해 본 후 그 중 최소 비용을 선정
		auto nextCheck = check | (1 << (i - 1));
		int result = find(i, dest, nextCheck) + W[x][i];
		answer = answer > result ? result : answer;
	}
	// 현재 정점에서 모든 경로 탐색 후 출발지로 돌아가는 최소 비용을 메모 후 리턴
	D[x][check] = answer;

	return D[x][check];
}