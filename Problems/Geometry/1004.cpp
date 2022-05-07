#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sresult;
vector<int> eresult;

void CheckIsInside(vector<int>& result, int x, int y, const vector<int>& cx, const vector<int>& cy, const vector<int>& r)
{
	for (int i = 0; i < cx.size(); i++)
	{
		// point is inside of circle
		if ((cx[i] - x) * (cx[i] - x) + (cy[i] - y) * (cy[i] - y) < r[i] * r[i])
		{
			result.push_back(1);
		}
		else
		{
			result.push_back(0);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		sresult.clear();
		eresult.clear();

		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		
		vector<int> cx;
		vector<int> cy;
		vector<int> rad;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int x, y, r;
			cin >> x >> y >> r;
			cx.push_back(x);
			cy.push_back(y);
			rad.push_back(r);
		}
		
		CheckIsInside(sresult, sx, sy, cx, cy, rad);
		CheckIsInside(eresult, ex, ey, cx, cy, rad);
		
		int answer = 0;
		for (int i = 0; i < sresult.size(); i++)
		{
			answer += (sresult[i] + eresult[i]) % 2;
		}
		cout << answer<<"\n";
	}

	return 0;
}