#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int64_t warpCount = 1;
		int64_t start, end;
		cin >> start >> end;

		auto n = end - start;

		int64_t i = 1;

		for (; i * i < n; i++);

		if (n <= (i - 1) * i)
			warpCount = 2 * (i - 1);
		else if (n > (i - 1) * i)
			warpCount = 2 * i - 1;

		cout << warpCount << endl;
	}

	return 0;
}