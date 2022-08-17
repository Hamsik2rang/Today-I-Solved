// ref to https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t answer[10];

void solution(int64_t n, int64_t ten)
{
    while (n > 0)
    {
        answer[n % 10] += ten;
        n = n / 10;
    }
}

int main()
{
    int64_t start = 1;
    int64_t end;
    int64_t base = 1;
    cin >> end;

    while (start <= end)
    {
        while (start % 10 != 0 && start <= end)
        {
            solution(start, base);
            start += 1;
        }

        if (start > end)
        {
            break;
        }

        while (end % 10 != 9 && start <= end)
        {
            solution(end, base);
            end -= 1;
        }

        int64_t cnt = (end / 10 - start / 10 + 1);
        for (int i = 0; i <= 9; i++)
        {
            answer[i] += cnt * base;
        }

        start /= 10;
        end /= 10;
		base *= 10;
    }

    for (int i = 0; i <= 9; i++)
    {
        cout << answer[i] << ' ';
    }

    return 0;
}