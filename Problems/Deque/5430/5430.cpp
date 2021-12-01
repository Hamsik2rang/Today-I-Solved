// Problem link: https://acmicpc.net/problem/5430
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//
// In this problem, function R reverses the given array, and D deletes the first element of the array at that point.
// the length N of the given array is at most 100,000, and the number of calls to the functions(R and D) is also 100,000.
// so naively reversing the array elements will occur time-out.
// 
// Therefore, instead of actually reversing the array, it 'assumes' that the array has been flipped, checks the front and back, 
// and delete the elements from the previous part at that point in time.
// 
// This structure can use a deque data structure that can delete data from either front or back, but since data insertion does not occur, 
// it can be solved using an array and two index pointers.
//

int main()
{
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		string s, func;
		int len;
		cin >> func >> len >> s;
		vector<int> arr;
		string temp{ "" };
		for (auto ptr = &s[0]; *ptr; ptr++)
		{
			if (*ptr == '[' || *ptr == ']')
			{
				continue;
			}
			else if (*ptr >= '0' && *ptr <= '9')
			{
				temp += *ptr;
			}
			else
			{
				arr.push_back(stoi(temp));
				temp = "";
				continue;
			}
		}

		if(temp.length()>0)
		{
			arr.push_back(stoi(temp));
		}

		int lptr = 0, rptr = arr.size() - 1;
		bool isLeftFront = true;
		bool isError = false;
		for (int i = 0; i < func.length(); i++)
		{
			
			switch (func[i])
			{
			case 'R':
				{
					isLeftFront ^= true;
				}
				break;
			case 'D':
				{
					if (lptr > rptr)
					{
						isError = true;
						break;
					}
					isLeftFront ? lptr++ : rptr--;
				}
				break;
			}
		}
		if (isError)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << "[";
			if (isLeftFront)
			{
				for (int i = lptr; i <= rptr; i++)
				{
					cout << arr[i];
					if (i != rptr) 
					{
						cout << ",";
					}
				}
			}
			else
			{
				for (int i = rptr; i >= lptr; i--)
				{
					cout << arr[i];
					if (i != lptr)
					{
						cout << ",";
					}
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}