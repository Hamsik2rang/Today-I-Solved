#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Info
{
	short age;
	int registerNum;
	string name;

	friend bool operator<(Info& l, Info& r);
};

bool operator<(Info& l, Info& r)
{
	if (l.age == r.age) 
	{
		return l.registerNum < r.registerNum;
	}
	return l.age < r.age;
}

Info info[100000];

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> info[i].age;
		cin >> info[i].name;
		info[i].registerNum = i;
	}

	sort(info, info + n);

	for (int i = 0; i < n; i++)
	{
		cout << info[i].age << " " << info[i].name << '\n';
	}

	return 0;
}