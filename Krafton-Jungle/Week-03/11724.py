import sys


def dfs(x: int) -> None:
    check[x] = True
    for next in graph[x]:
        if check[next]:
            continue
        dfs(next)


check = [False for i in range(1001)]
graph = [[] for i in range(1001)]
ans = 0

n, m = map(int, sys.stdin.readline().split())
for _ in range(m):
    src, dest = map(int, sys.stdin.readline().split())
    graph[src].append(dest)
    graph[dest].append(src)


for i in range(1, n + 1):
    if check[i]:
        continue
    dfs(i)
    ans += 1

print(ans)
