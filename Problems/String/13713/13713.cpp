#include <iostream>
#include <vector>

using namespace std;

string s; int m;

struct Hash
{
	//1e9-63, 1e9+7, 1e9+9, 1e9+103
	//1e5+3, 1e5+13, 131071, 524287
	vector<int64_t> hash, base;
	int64_t p, mod;

	Hash()
	{
		p = 1e9 - 63, mod = 524287;
	}

	Hash(int64_t _p, int64_t _mod) : p(_p), mod(_mod) {}

	Hash(string& s, int64_t _p, int64_t _mod) : Hash(_p, _mod)
	{
		int n = s.size();
		hash = vector<int64_t>(n + 1, 0);
		base = vector<int64_t>(n + 1, 0);
		base[0] = 1; base[1] = p;
		for (int i = n - 1; i >= 0; i--)
		{
			hash[i] = (s[i] + hash[i + 1] * p) % mod;
		}
		for (int i = 2; i <= n; i++)
		{
			base[i] = base[i - 1] * p % mod;
		}
	}

	int substring(int l, int r)
	{
		int64_t ret = hash[l] - hash[r + 1] * base[r - l + 1];
		ret %= mod; 
		ret += mod; 
		ret %= mod;

		return ret;
	}
}h1, h2;



bool chk(int q, int x)
{
	if (x == 0) 
	{
		return 1;
	}
	if (x > s.size() || x > q) 
	{
		return 0;
	}

	int a = h1.substring(s.size() - x, s.size() - 1);
	int b = h1.substring(q - x, q - 1);

	int aa = h2.substring(s.size() - x, s.size() - 1);
	int bb = h2.substring(q - x, q - 1);

	return a == b && aa == bb;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s >> m;
	h1 = Hash(s, 1e9 - 63, 131071);
	h2 = Hash(s, 1e9 + 9, 100005);
	while (m--)
	{
		int t; 
		cin >> t;

		int l = 0, r = t, mid = (l + r) / 2;
		while (l <= r)
		{
			mid = (l + r) / 2;
			bool now = chk(t, mid);
			bool prv = chk(t, mid + 1);

			if (now && !prv) 
			{
				break;
			}
			if (!now) 
			{
				r = mid - 1;
			}
			else 
			{
				l = mid + 1;
			}
		}
		cout << mid << "\n";
	}
}