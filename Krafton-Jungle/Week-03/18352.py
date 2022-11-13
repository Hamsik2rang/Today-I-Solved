import sys
from collections import deque


def bfs(x: int) -> None:
    global k

    q = deque()
    check = [False for _ in range(n + 1)]
    check[x] = True
    q.append((x, 0))

    while len(q) > 0:
        cur, cur_count = q.popleft()

        if cur_count == k:
            answer.append(cur)

        for next in graph[cur]:
            if check[next]:
                continue
            check[next] = True
            q.append((next, cur_count + 1))


n, m, k, x = map(int, sys.stdin.readline().split())
answer = []
graph = [[] for _ in range(n + 1)]
for i in range(m):
    src, dest = map(int, sys.stdin.readline().split())
    graph[src].append(dest)

bfs(x)

if len(answer) == 0:
    print(-1)
else:
    answer.sort()
    for vertex in answer:
        print(vertex)
