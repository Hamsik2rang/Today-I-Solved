import sys
from collections import deque


def bfs(row: int, col: int) -> int:
    dr = [-1, 0, 1, 0]
    dc = [0, -1, 0, 1]

    q = deque()
    check = [[False for _ in range(m)] for _ in range(n)]
    check[row][col] = True
    q.append((row, col, 1))

    while len(q) > 0:
        cr, cc, cur_count = q.popleft()

        if cr == n - 1 and cc == m - 1:
            return cur_count

        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]
            if nr < 0 or nr >= n or nc < 0 or nc >= m:
                continue
            if check[nr][nc] or graph[nr][nc] == "0":
                continue

            check[nr][nc] = True
            q.append((nr, nc, cur_count + 1))


n, m = map(int, sys.stdin.readline().split())
graph = [None for _ in range(n)]
for i in range(n):
    graph[i] = sys.stdin.readline().strip()

print(bfs(0, 0))
