#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
T TenarySearch(vector<T>& v, T search)
{
	int left = 0;
	int right = v.size() - 1;
	while (left < right)
	{
		int one_third = left + ((right - left + 1) / 3);
		int two_third = left + ((right - left + 1) * 2 / 3);
		if (search < v[one_third])
			right = one_third;
		else if (search > v[two_third])
			left = two_third;
		else if (search == v[one_third])
			return 1;
		else if (search == v[two_third])
			return 1;
		else
		{
			left = one_third + 1;
			right = two_third;
		}
	}
	return 0;
}

int main()
{

	vector<int> v;
	vector<int> findVector;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;
		findVector.push_back(temp);
	}
	auto size = findVector.size();
	for (int i = 0; i < size; i++)
	{
		cout << TenarySearch<int>(v, findVector[i]) << '\n';
	}

	return 0;
}