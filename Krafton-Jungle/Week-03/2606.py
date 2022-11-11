import sys


def dfs(x: int) -> int:
    check[x] = True
    ans = 1
    for next in graph[x]:
        if check[next]:
            continue
        ans += dfs(next)
    return ans


check = [False for i in range(1001)]
graph = [[] for i in range(1001)]
ans = 0

v = int(sys.stdin.readline())
e = int(sys.stdin.readline())
for _ in range(e):
    src, dest = map(int, sys.stdin.readline().split())
    graph[src].append(dest)
    graph[dest].append(src)

print(dfs(1) - 1)
