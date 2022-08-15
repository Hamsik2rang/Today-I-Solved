#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		priority_queue<int, vector<int>, less<>> Mpq;
		priority_queue<int, vector<int>, greater<>> mpq;
		unordered_map<int, int> m;
		int k;
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			char query;
			int num;
			cin >> query >> num;
			// »ðÀÔ
			if (query == 'I')
			{
				Mpq.push(num);
				mpq.push(num);
				m[num] = m[num] + 1;
			}
			//»èÁ¦
			else
			{
				// ÃÖ´ñ°ª »èÁ¦
				if (num == 1)
				{
					while (!Mpq.empty() && m[Mpq.top()] == 0)
					{
						Mpq.pop();
					}
					if (!Mpq.empty())
					{
						m[Mpq.top()]--;
						Mpq.pop();
					}
				}
				// ÃÖ¼Ú°ª »èÁ¦
				else
				{
					while (!mpq.empty() && m[mpq.top()] == 0)
					{
						mpq.pop();
					}
					if (!mpq.empty())
					{
						m[mpq.top()]--;
						mpq.pop();
					}
				}
			}
		}

		while (!Mpq.empty() && m[Mpq.top()] == 0)
		{
			Mpq.pop();
		}
		while (!mpq.empty() && m[mpq.top()] == 0)
		{
			mpq.pop();
		}

		if (Mpq.empty() && mpq.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << Mpq.top() << " " << mpq.top() << "\n";
		}
	}

	return 0;
}