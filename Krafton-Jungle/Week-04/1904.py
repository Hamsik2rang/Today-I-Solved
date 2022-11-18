import sys

n = int(sys.stdin.readline())
memo = [0] * 1_000_001
memo[0], memo[1] = 1, 1

for i in range(2, n + 1):
    memo[i] = (memo[i - 2] + memo[i - 1]) % 15746

print(memo[n])
