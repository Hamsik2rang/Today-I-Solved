#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 길이가 최소 l인 연속된 수열의 합이 n인 경우 다음과 같음
	// k + (k+1) + (k+2) + ... + (k+l-1) = n
	// lk + sigma(i=0 to l-1)a = n
	// 식을 풀면 아래와 같음
	// (1/2)l^2 + (k-(1/2))l = n
	// k, l, n 모두 자연수이므로 실수 연산을 방지하기 위해 양변에 2를 곱함
	// l^2 + (2k-1)l = 2n
	// 이 식을 만족하는 k를 찾으면 k부터 k+l-1까지 출력하면 정답

	int n, l;
	cin >> n >> l;

	while (l <= 100)
	{
		int k = n / l;
		while (k >= 0)
		{
			auto result = l * l + (2 * k - 1) * l;
			if (result == 2 * n)
			{
				for (int i = 0; i < l; i++)
				{
					cout << k + i << " ";
				}
				return 0;
			}
			else if (result > 2 * n)
			{
				k--;
			}
			else
			{
				break;
			}
		}
		l++;
	}
	cout << -1;

	return 0;
}