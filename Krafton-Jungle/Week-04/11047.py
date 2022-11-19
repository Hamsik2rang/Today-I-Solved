import sys

n, k = map(int, sys.stdin.readline().split())
coin = [0 for _ in range(n)]
for i in range(n):
    coin[i] = int(sys.stdin.readline())

answer = 0
index = n

while k > 0 and index >= 0:
    index -= 1

    if coin[index] > k:
        continue
    answer += k // coin[index]
    k %= coin[index]

print(answer)
