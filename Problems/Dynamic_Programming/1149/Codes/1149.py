# min of R, G, B of index n-1 (==n th)
memo = {}
cost = {}

R, G, B = 0, 1, 2


def get_cost(n):
    for i in range(n):
        cost_list = list(map(int, input().split()))
        cost[i] = cost_list


# Use Recursion - It raised RecursionError(maximum recursion depth)
# def solution(n):
#     if n == 0:
#         return (cost[0][R], cost[0][G], cost[0][B])

#     if n not in memo:
#         memo[n] = {}
#         r, g, b = solution(n - 1)
#         memo[n][R] = min(g, b) + cost[n][R]
#         memo[n][G] = min(r, b) + cost[n][G]
#         memo[n][B] = min(r, g) + cost[n][B]
#     return (memo[n][R], memo[n][G], memo[n][B])


def solution(n):
    memo[0] = cost[0]

    for i in range(1, n):
        memo[i] = {}
        memo[i][R] = min(memo[i - 1][G], memo[i - 1][B]) + cost[i][R]
        memo[i][G] = min(memo[i - 1][R], memo[i - 1][B]) + cost[i][G]
        memo[i][B] = min(memo[i - 1][R], memo[i - 1][G]) + cost[i][B]

    return min(memo[n - 1][R], memo[n - 1][G], memo[n - 1][B])


n = int(input())
get_cost(n)
print(solution(n))