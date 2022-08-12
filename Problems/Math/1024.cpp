#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// ���̰� �ּ� l�� ���ӵ� ������ ���� n�� ��� ������ ����
	// k + (k+1) + (k+2) + ... + (k+l-1) = n
	// lk + sigma(i=0 to l-1)a = n
	// ���� Ǯ�� �Ʒ��� ����
	// (1/2)l^2 + (k-(1/2))l = n
	// k, l, n ��� �ڿ����̹Ƿ� �Ǽ� ������ �����ϱ� ���� �纯�� 2�� ����
	// l^2 + (2k-1)l = 2n
	// �� ���� �����ϴ� k�� ã���� k���� k+l-1���� ����ϸ� ����

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