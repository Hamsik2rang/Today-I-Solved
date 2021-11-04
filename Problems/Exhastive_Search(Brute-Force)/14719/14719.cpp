#include <iostream>
#include <vector>

int main()
{
	int height, width;
	int answer = 0;
	std::cin >> height >> width;

	std::vector<int> block(width);
	for (auto& e : block)
	{
		std::cin >> e;
	}

	for (int i = 1; i < width - 1; i++)
	{
		int left = 0, right = 0;
		for (int j = 0; j < i; j++)
		{
			left = std::max(left, block[j]);
		}
		for (int j = i + 1; j < width; j++)
		{
			right = std::max(right, block[j]);
		}
		answer += std::max(0, std::min(left, right) - block[i]);
	}
	std::cout << answer << std::endl;

	return 0;
}