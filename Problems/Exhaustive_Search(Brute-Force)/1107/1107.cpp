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

	// case 0 - 100에서 +/- 버튼만으로 이동하는 경우
	int answer = abs(n - 100);

	if (n <= 103 && n >= 98)
	{
		cout << answer << endl;
		return 0;
	}

	// case 1 - 목표 채널보다 낮은 채널을 직접 입력 후 +버튼만으로 이동하는 경우
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

	// case 2 - 목표 채널보다 높은 채널을 직접 입력 후 -버튼만으로 이동하는 경우
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
	//입력해야 할 채널이 0인데 0이 고장났거나, 답이 될 수 있는 범위 밖의 채널을 입력한 경우
	if (target == 0 && broken[0] || target > 1e6)	
	{
		return false;
	}

	// 채널의 각 자릿수별로 고장난 버튼에 매핑되는 숫자가 있는지 파악
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