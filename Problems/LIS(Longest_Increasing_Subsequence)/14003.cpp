#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> index;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	vector<int> v;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		arr.push_back(num);
	
		if (v.empty() || v.back() < num)
		{
			v.push_back(num);
			index.push_back(v.size() - 1);
		}
		else
		{
			auto iter = lower_bound(v.begin(), v.end(), num);
			*iter = num;
			index.push_back(iter - v.begin());
		}
	}
	
	int size = v.size();
	cout << size << "\n";
	// v�� ���̴� ���� ������ ���̿� ������, �� ������ ���� ���� ������ �ٸ�.
	// ���� �޸��� index�� �������� ���� ���� ������ ã����� ��.
	stack<int> answer;
	for (int i = index.size() - 1; i >= 0 && size > 0; i--)
	{
		if (index[i] != size - 1)
		{
			continue;
		}
		answer.push(arr[i]);
		size--;
	}

	while (!answer.empty())
	{
		cout << answer.top() << " ";
		answer.pop();
	}

	return 0;
}