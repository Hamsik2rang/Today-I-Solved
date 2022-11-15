import sys
from collections import deque

col, row, height = map(int, sys.stdin.readline().split())
q = deque()

graph = [[[0 for _ in range(col)] for _ in range(row)] for _ in range(height)]
check = [[[False for _ in range(col)] for _ in range(row)] for _ in range(height)]
for h in range(height):
    for r in range(row):
        graph[h][r] = list(map(int, sys.stdin.readline().split()))
        for c in range(col):
            if graph[h][r][c] == 1:
                check[h][r][c] = True
                q.append((h, r, c))


while len(q) > 0:
    dh = [-1, 0, 0, 1, 0, 0]
    dr = [0, -1, 0, 0, 1, 0]
    dc = [0, 0, -1, 0, 0, 1]
    ch, cr, cc = q.popleft()

    for i in range(6):
        nh = ch + dh[i]
        nr = cr + dr[i]
        nc = cc + dc[i]

        if nh < 0 or nh >= height or nr < 0 or nr >= row or nc < 0 or nc >= col:
            continue

        if check[nh][nr][nc] or graph[nh][nr][nc] < 0:
            continue

        check[nh][nr][nc] = True
        graph[nh][nr][nc] = graph[ch][cr][cc] + 1
        q.append((nh, nr, nc))

answer = -1
for h in range(height):
    for r in range(row):
        for c in range(col):
            if graph[h][r][c] < 0:
                continue
            if graph[h][r][c] == 0:
                print(-1)
                exit(0)

            answer = max(answer, graph[h][r][c])
print(answer - 1)
