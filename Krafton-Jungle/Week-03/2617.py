import sys

sys.setrecursionlimit(10**5 * 2)


def dfs(graph: list, x: int) -> int:
    check[x] = True
    count = 1
    for next in graph[x]:
        if check[next]:
            continue
        count += dfs(graph, next)

    return count


n, m = map(int, sys.stdin.readline().split())

light_weight_graph = [[] for _ in range(n + 1)]
heavy_weight_graph = [[] for _ in range(n + 1)]
for _ in range(m):
    src, dest = map(int, sys.stdin.readline().split())
    light_weight_graph[src].append(dest)
    heavy_weight_graph[dest].append(src)

answer = 0
for i in range(1, n + 1):
    check = [False for _ in range(n + 1)]
    light_marble_count = dfs(light_weight_graph, i) - 1
    check = [False for _ in range(n + 1)]
    heavy_marble_count = dfs(heavy_weight_graph, i) - 1

    if light_marble_count >= (n + 1) // 2 or heavy_marble_count >= (n + 1) // 2:
        answer += 1

print(answer)
