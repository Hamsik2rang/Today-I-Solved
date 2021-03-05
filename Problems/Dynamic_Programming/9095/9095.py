# Problem no.9095
# Print Num of expression of an Integer as Sum of 1,2,3.

# Dictionary for Memoization.
memo = {}


def solution(n):
    if n < 4:
        # If can't get solution(n-1) and others.
        if n == 1:
            memo[n] = 1 if 1 not in memo else memo[n]
            return memo[n]
        # If can't get solution(n-2) and another.
        elif n == 2:
            memo[n] = solution(n - 1) + 1 if 2 not in memo else memo[n]
            return memo[n]
        # If can't get solution(n-3).
        elif n == 3:
            memo[n] = (
                solution(n - 1) + solution(n - 2) + 1 if 3 not in memo else memo[n]
            )
            return memo[n]
        # 0 can't express as Sum of 1,2,3.
        else:
            return 0
    # Recurrence relation.
    return solution(n - 1) + solution(n - 2) + solution(n - 3)


count = int(input())

for _ in range(count):
    n = int(input())
    print(solution(n))
