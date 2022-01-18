#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

using Pos = std::pair<int, int>;
using Command = std::pair<int, char>;

bool IsGameOver(const std::deque<Pos>& snake, const int& n)
{
	return (std::find(snake.begin() + 1, snake.end(), snake.front()) != snake.end() 
		|| snake.front().first > n || snake.front().first < 1 
		|| snake.front().second > n || snake.front().second < 1);
}

int main()
{
	std::deque<Pos> snake(1, std::make_pair(1, 1));
	std::vector<Pos> moveBuffer(1, std::make_pair(0, 1));
	std::deque<std::pair<Pos,bool>> apples;
	//n = The Edge Length of Board, k = Number of Apples, l = Number of Rotation.
	int n, k, l;
	int count = 0;

	std::cin >> n >> k;


	for (int i = 0; i < k; i++)
	{
		Pos apple;
		bool isEaten = false;
		std::cin >> apple.first >> apple.second;
		apples.push_back(make_pair(apple,isEaten));
	}

	std::cin >> l;
	int dr = 0;
	int dc = 1;
	for (int i = 0; i < l; i++)
	{
		int sec;
		char command;

		std::cin >> sec >> command;
		while (moveBuffer.size() < sec)
		{
			moveBuffer.push_back(std::make_pair(dr, dc));
		}
		if (command == 'D')
		{
			auto temp = dr;
			dr = dc;
			dc = -temp;
		}
		else if (command == 'L')
		{
			auto temp = dr;
			dr = -dc;
			dc = temp;
		}
		moveBuffer.push_back(std::make_pair(dr, dc));
	}

	for (int i = 0;; i++, count++)
	{
		Pos movePos = moveBuffer.size() <= i ? moveBuffer[moveBuffer.size() - 1] : moveBuffer[i];
		Pos nextHeadPos = std::make_pair(snake.front().first + movePos.first, snake.front().second + movePos.second);
		snake.push_front(nextHeadPos);
		if (IsGameOver(snake, n))
		{
			count++;
			break;
		}
		auto apple = std::find(apples.begin(), apples.end(), make_pair(snake.front(),false));
		if (apple != apples.end())
		{
			(*apple).second = true;
		}
		else
		{
			snake.pop_back();
		}
	}
	std::cout << count;
	return 0;
}