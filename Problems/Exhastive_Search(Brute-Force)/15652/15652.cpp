#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solution(int arr[], int index, int last, const int n, const int m);

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	//1부터 n까지 중 m개의 자연수를 고른 수열 중 비내림차순인 수열
	cin >> n >> m;

	int num = 1;
	int arr[8];
	solution(arr, 0, 1, n, m);

	return 0;
}

void solution(int arr[], int index, int last,  const int n, const int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = last; i <= n; i++)
	{
		arr[index] = i;
		solution(arr, index + 1, i, n, m);
	}
}
