#include <iostream>
#include <vector>
#include <algorithm>

bool compare(const std::string& s1, const std::string& s2)
{
	if (s1.length() != s2.length())
	{
		return (s1.length() < s2.length());
	}
	else
	{
		return s1 < s2;
	}
}


int main()
{
	std::vector<std::string> v;
	int n;
	std::cin >> n;
	while (n--)
	{
		std::string s;

		std::cin >> s;

		std::vector<std::string>::iterator iter = std::find(v.begin(), v.end(), s);

		if (iter == v.end())
		{
			v.push_back(s);
		}
	}

	std::sort(v.begin(), v.end(), compare);

	for (auto s : v)
	{
		std::cout << s << '\n';
	}

	return 0;
}