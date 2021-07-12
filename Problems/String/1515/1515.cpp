#include <iostream>
#include <string>

using namespace std;

bool compare(string& s, const int& i)
{
	static int ptr = 0;

	if (ptr == s.size())
	{
		return true;
	}

	string num = to_string(i);

	for (int i = 0; i < num.size(); i++)
	{
		if (ptr<s.size() && num[i] == s[ptr])
		{
			ptr++;
		}
	}
	return false;
}

int main()
{
	string s = "";
	cin >> s;

	int min = 1;
	for (min = 1; ; min++)
	{
		if (compare(s, min))
		{
			break;
		}
	}
	cout << min - 1 << endl;

	return 0;
}