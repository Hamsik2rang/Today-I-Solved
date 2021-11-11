#include <iostream>
#include <string>

#define MOD 1234567891

using namespace std;

unsigned long long getHash(const string& s)
{
	unsigned long long hash = 0;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		hash = (((hash * 31) % MOD) + (s[i] - 'a' + 1)) % MOD;
	}

	return hash % MOD;
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	cout << getHash(s);

	return 0;
}