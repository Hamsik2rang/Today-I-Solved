from collections import deque
import sys

check = [False for i in range(1001)]
graph = [[] for i in range(1001)]


def dfs(x: int) -> None:
    check[x] = True
    print(x, end=" ")
    for next in graph[x]:
        if check[next]:
            continue
        dfs(next)


def bfs(x: int) -> None:
    q = deque()
    check[x] = True
    q.append(x)
    while len(q) > 0:
        cur = q.popleft()
        print(cur, end=" ")
        for next in graph[cur]:
            if check[next]:
                continue
            check[next] = True
            q.append(next)


n, m, v = map(int, sys.stdin.readline().split())
for _ in range(m):
    src, dest = map(int, sys.stdin.readline().split())
    graph[src].append(dest)
    graph[dest].append(src)

for i in range(1, n + 1):
    graph[i].sort()

dfs(v)
check = [False for i in range(1001)]
print()
bfs(v)
