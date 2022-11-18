import sys


def solution(left: int, right: int) -> int:
    if left == right:
        return 0

    if right - left == 1:
        return matrix[left][0] * matrix[left][1] * matrix[right][1]

    if memo[left][right]:
        return memo[left][right]

    memo[left][right] = 0x7FFFFFFF
    for mid in range(left, right):
        memo[left][right] = min(
            memo[left][right],
            solution(left, mid)
            + solution(mid + 1, right)
            + matrix[left][0] * matrix[mid][1] * matrix[right][1],
        )
    return memo[left][right]


n = int(sys.stdin.readline())
matrix = [[] for _ in range(501)]
memo = [[0 for _ in range(501)] for _ in range(501)]
for i in range(n):
    matrix[i] = list(map(int, sys.stdin.readline().split()))

print(solution(0, n - 1))
