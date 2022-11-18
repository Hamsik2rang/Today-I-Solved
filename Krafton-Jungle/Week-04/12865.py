import sys


def solution(index: int, weight: int) -> int:
    global n, k
    if index == n:
        return 0
    if memo[index][weight]:
        return memo[index][weight]

    if knapsack[index][0] + weight > k:
        memo[index][weight] = solution(index + 1, weight)
    else:
        memo[index][weight] = max(
            solution(index + 1, weight),
            solution(index + 1, weight + knapsack[index][0]) + knapsack[index][1],
        )

    return memo[index][weight]


n, k = map(int, sys.stdin.readline().split())
knapsack = []
memo = [[0 for _ in range(k + 1)] for _ in range(n)]
for _ in range(n):
    knapsack.append(list(map(int, sys.stdin.readline().split())))

print(solution(0, 0))
