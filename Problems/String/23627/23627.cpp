#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	cout << (s.find("driip", s.length() - 5) == string::npos ? "not cute" : "cute");
	
	return 0;
}