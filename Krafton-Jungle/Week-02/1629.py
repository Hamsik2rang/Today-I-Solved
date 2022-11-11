import sys


def solution(a, b, c):
    if b == 1:
        return a % c

    if b % 2 == 1:
        result = solution(a, (b - 1) // 2, c)
        ans = (result * result * solution(a, 1, c)) % c
    else:
        result = solution(
            a,
            b // 2,
            c,
        )
        ans = (result * result) % c
    return ans


a, b, c = map(int, sys.stdin.readline().split())
print(solution(a, b, c))
