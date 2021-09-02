#define _CRT_SECURE_NO_WARNINGS
#define MAXN (100001)

#include <iostream>

using namespace std;

void solution(int inStart, int inEnd, int postStart, int postEnd);

int inorder[MAXN], postorder[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "r", stdin);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}

	solution(0, n - 1, 0, n - 1);
	return 0;
}

void solution(int inStart, int inEnd, int postStart, int postEnd)
{
	if (inStart > inEnd || postStart > postEnd)
	{
		return;
	}

	cout << postorder[postEnd] << " ";
	
	int rootIdx;
	for (rootIdx = inStart; rootIdx < inEnd; rootIdx++)
	{
		if (inorder[rootIdx] == postorder[postEnd])
		{
			break;
		}
	}
	solution(inStart, rootIdx - 1, postStart, postStart + (rootIdx - inStart) - 1);
	solution(rootIdx + 1, inEnd, postStart + (rootIdx - inStart), postEnd - 1);
}