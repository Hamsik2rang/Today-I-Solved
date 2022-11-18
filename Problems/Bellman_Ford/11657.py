import sys


def bellman_ford(start: int) -> bool:
    global n, m
    dist[start] = 0

    for i in range(n):
        for j in range(m):
            cur, next, cost = bus[j]
            if dist[cur] != 0x7FFFFFFF and dist[next] > dist[cur] + cost:
                dist[next] = dist[cur] + cost
                if i == n - 1:
                    return True
    return False


n, m = map(int, sys.stdin.readline().split())
bus = [[] for _ in range(m)]
dist = [0x7FFFFFFF for _ in range(n + 1)]
for i in range(m):
    bus[i] = list(map(int, sys.stdin.readline().split()))

if bellman_ford(1):
    print(-1)
else:
    for i in range(2, len(dist)):
        if dist[i] == 0x7FFFFFFF:
            print(-1)
        else:
            print(dist[i])
