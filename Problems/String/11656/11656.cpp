#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	vector<string> prefix;

	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		string temp = "";
		for (int j = i; j < s.length(); j++)
		{
			temp += s[j];
		}
		prefix.push_back(temp);
	}

	sort(prefix.begin(), prefix.end());

	for (int i = 0; i < prefix.size(); i++)
	{
		cout << prefix[i] << endl;
	}

	return 0;
}