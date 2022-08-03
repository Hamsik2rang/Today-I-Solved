#include <iostream>

using namespace std;

#define MOD 1'000'000'007

struct Mat22
{
	uint64_t e[2][2];

	uint64_t* operator[](int index) 
	{ 
		return e[index];
	}
	Mat22 operator*(Mat22 m)
	{
		Mat22 result{};
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					result[i][j] += e[i][k] * m[k][j];
				}
				result[i][j] %= MOD;
			}
		}

		return result;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	uint64_t n;
	cin >> n;
	Mat22 mul{ 1, 1, 1, 0 };
	Mat22 answer{ 1, 0, 0, 1 };

	while (n)
	{
		if (n & 1)
		{
			answer = answer * mul;
		}
		mul = mul * mul;
		n /= 2;
	}
	cout << answer[0][1];

	return 0;
}