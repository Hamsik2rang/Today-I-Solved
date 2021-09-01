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
	// 1�� �������� ����ϸ�, 1�� �������� �ǵ��ƿ;� �ϰ� 1������ �����ϹǷ� �湮 ��Ʈ�� �����ʿ��� ù ��°(2^0) ��Ʈ set, ��� ����� �����Ƿ� 0���� ȣ��
	int answer = find(1, 1, 1);
	cout << answer << "\n";

	return 0;
}

int find(int x, const int dest, int check)
{
	// �̹� ���� �湮 ���¿����� Ž�� ����� �޸�Ǿ� �ִٸ� �ش� ���� ����
	if (D[x][check] != -1)
	{
		return D[x][check];
	}

	// ��� ������ �湮�ߴٸ�
	if (check == (1 << N) - 1)
	{
		// ��� �������� ���ư� �� ���� ���(�������� ���� ���)
		if (!W[x][dest])
		{
			return INF;
		}
		// ���ư� �� �ִ� ���
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
		// �湮�� ������ ����
		if (!W[x][i] || (check & (1 << (i - 1))))
		{
			continue;
		}
		// �湮���� ���� ������ ��� ������ �湮�� �� �� �� �� �ּ� ����� ����
		auto nextCheck = check | (1 << (i - 1));
		int result = find(i, dest, nextCheck) + W[x][i];
		answer = answer > result ? result : answer;
	}
	// ���� �������� ��� ��� Ž�� �� ������� ���ư��� �ּ� ����� �޸� �� ����
	D[x][check] = answer;

	return D[x][check];
}