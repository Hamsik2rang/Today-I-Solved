import sys

sys.setrecursionlimit(10**5)


def dfs(x: int, g: int) -> bool:
    group[x] = g
    for next in graph[x]:
        if group[next] == 0:
            dfs(next, 3 - g)


k = int(sys.stdin.readline())
while k > 0:
    k -= 1

    v, e = map(int, sys.stdin.readline().split())
    graph = [[] for i in range(v + 1)]
    group = [0 for i in range(v + 1)]
    for _ in range(e):
        src, dest = map(int, sys.stdin.readline().split())
        graph[src].append(dest)
        graph[dest].append(src)

    for i in range(v + 1):
        if group[i] == 0:
            dfs(i, 1)
    is_bipartite = True
    for i in range(1, v + 1):
        for next in graph[i]:
            if group[i] == group[next]:
                is_bipartite = False
                break
    print("YES" if is_bipartite else "NO")
    del graph
    del group
