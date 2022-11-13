import sys
from collections import deque


def bfs(x: int, remain: int) -> int:
    check = [False for i in range(10001)]
    q = deque()
    q.append((x, remain - x, 1))

    while len(q) > 0:
        cur_value, cur_remain, cur_count = q.popleft()

        if cur_remain == 0:
            return cur_count

        for coin in coin_list:
            if cur_remain - coin < 0 or check[cur_remain - coin]:
                continue
            check[cur_remain - coin] = True
            q.append((coin, cur_remain - coin, cur_count + 1))

    return -1


n, k = map(int, sys.stdin.readline().split())
coin_list = []
for _ in range(n):
    num = int(sys.stdin.readline())
    coin_list.append(num)

coin_list.sort(reverse=True)
answer = -1
for coin in coin_list:
    result = bfs(coin, k)
    if result > 0 and (answer < 0 or answer > result):
        answer = result

print(answer)
