#include <iostream>
#include <algorithm>

using namespace std;

bool check(int target);

bool broken[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		broken[input] = true;
	}

	// case 0 - 100���� +/- ��ư������ �̵��ϴ� ���
	int answer = abs(n - 100);

	if (n <= 103 && n >= 98)
	{
		cout << answer << endl;
		return 0;
	}

	// case 1 - ��ǥ ä�κ��� ���� ä���� ���� �Է� �� +��ư������ �̵��ϴ� ���
	int target = n;
	int count = 0;
	while (!check(target))
	{
		if (target < 0)
		{
			break;
		}
		count++;
		target--;
	}
	if (target >= 0)
	{
		if (target == 0) count++;
		else
		{
			while (target > 0)
			{
				count++;
				target /= 10;
			}
		}
		answer = answer > count ? count : answer;
	}

	// case 2 - ��ǥ ä�κ��� ���� ä���� ���� �Է� �� -��ư������ �̵��ϴ� ���
	target = n;
	count = 0;
	while (!check(target))
	{
		if (target > 1e6)
		{
			break;
		}
		count++;
		target++;
	}

	if (target <= 1e6)
	{
		if (target == 0) count++;
		else
		{
			while (target > 0)
			{
				target /= 10;
				count++;
			}
		}
		answer = answer > count ? count : answer;
	}

	cout << answer << endl;

	return 0;
}

bool check(int target)
{
	//�Է��ؾ� �� ä���� 0�ε� 0�� ���峵�ų�, ���� �� �� �ִ� ���� ���� ä���� �Է��� ���
	if (target == 0 && broken[0] || target > 1e6)	
	{
		return false;
	}

	// ä���� �� �ڸ������� ���峭 ��ư�� ���εǴ� ���ڰ� �ִ��� �ľ�
	while (target > 0)	
	{
		if (broken[target % 10])
		{
			return false;
		}
		target /= 10;
	}

	return true;
}