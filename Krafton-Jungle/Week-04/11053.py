import sys

n = int(sys.stdin.readline())
sequence = list(map(int, sys.stdin.readline().split()))
memo = [1 for _ in range(1001)]

for i in range(n):
    for j in range(i):
        if sequence[i] > sequence[j] and memo[j] + 1 > memo[i]:
            memo[i] = memo[j] + 1

print(max(memo))
