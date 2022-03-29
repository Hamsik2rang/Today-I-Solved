#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long a, long long b)
{
	while (a % b)
	{
		long long temp = a % b;
		a = b;
		b = temp;
	}
	return b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	auto div = m / n;
	long long ansA = 100'000'000;
	long long ansB = 100'000'000;
	for (register long long i = 1; i * i <= div; i++)
	{
		
		if (div % i)
		{
			continue;
		}
		long long a = i;
		long long b = div / i;

		if (GCD(a, b) > 1)
		{
			continue;
		}
		a *= n;
		b *= n;
		ansA = a;
		ansB = b;
	}
	cout << ansA << " " << ansB;

	return 0;
}