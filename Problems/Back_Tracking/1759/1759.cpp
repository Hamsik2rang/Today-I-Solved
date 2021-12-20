#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void solution(const vector<char>& v, int index, string s);
int l, c;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> l >> c;
	vector<char> v(c);
	for (int i = 0; i < c; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	solution(v,0, "");

	return 0;
}

void solution(const vector<char>& v, int index, string s)
{
	if (s.length() >= l)
	{
		int consonant = 0, vowel = 0;
		bool isAnswer = false;
		for (const auto& e : s)
		{
			if (e == 'a' || e == 'i' || e == 'o' || e == 'e' || e == 'u')
				vowel++;
			else
				consonant++;
		}
		if (consonant >= 2 && vowel >= 1)
			cout << s << "\n";

		return;
	}

	for (int i = index; i < c; i++)
	{
		string next = s + v[i];
		solution(v, i + 1, next);
	}
}