#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book)
{
	unordered_map<string, bool> m;
	for (const auto& e : phone_book)
	{
		m[e] = true;
	}

	for (int i = 0; i < phone_book.size(); i++)
	{
		string num{ "" };
		for (int j = 0; j < phone_book[i].length(); j++)
		{
			num += phone_book[i][j];
			if (m[num] && num != phone_book[i])
			{
				return false;
			}
		}
	}

	return true;
}