#include <iostream>
#include <algorithm>

#define MAXN 8

using namespace std;

int N, M;
int d[MAXN];
int visited[MAXN];

void solution(int idx, int start, int cnt);

int main(void)
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> d[i];
	}

	sort(d, d + N);

	solution(0, 0, 0);

	return 0;
}

void solution(int index, int start, int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << d[visited[i]] << " ";
		}
		cout << "\n";

		return;
	}

	if (index == N)
	{
		return;
	}

	for (int i = start; i < N; i++)
	{
		visited[index] = i;

		solution(index + 1, i, count + 1);
	}
}