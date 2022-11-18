import sys

tc = int(sys.stdin.readline())
while tc > 0:
    tc -= 1

    n = int(sys.stdin.readline())
    coin_list = list(map(int, sys.stdin.readline().split()))
    m = int(sys.stdin.readline())
    memo = [0 for _ in range(10001)]
    memo[0] = 1
    for i in range(0, n):
        for j in range(coin_list[i], m + 1):
            memo[j] += memo[j - coin_list[i]]
    print(memo[m])
