#include <iostream>
#include <cmath>

using namespace std;

int divide(int n, int row, int col, int startRow, int startCol, int start, int end);

int main()
{
	int n, r, c;
	cin >> n >> r >> c;

	int area = pow(2, n) * pow(2, n) - 1;

	cout << divide(n, r, c, 0, 0, 0, area);

	return 0;
}

int divide(int n, int row, int col, int startRow, int startCol, int start, int end)
{
	if (start == end)
	{
		return start;
	}

	int halfSide = pow(2, n - 1);
	int nextArea = pow(2, 2 * n - 2);
	// quadrant 1
	if (col < startCol + halfSide && row < startRow + halfSide)
	{
		return divide(n - 1, row, col, startRow, startCol, 0 * nextArea + start, 1 * nextArea - 1 + start);
	}
	// quadrant 2
	else if (col >= startCol + halfSide && row < startRow + halfSide)
	{
		return divide(n - 1, row, col, startRow, startCol + halfSide, 1 * nextArea + start, 2 * nextArea - 1 + start);
	}
	// quadrant 3
	else if (col < startCol + halfSide && row >= startRow + halfSide)
	{
		return divide(n - 1, row, col, startRow + halfSide, startCol, 2 * nextArea + start, 3 * nextArea - 1 + start);
	}
	// quadrant 4
	else
	{
		return divide(n - 1, row, col, startRow + halfSide, startCol + halfSide, 3 * nextArea + start, 4 * nextArea - 1 + start);
	}
}