import sys
from collections import deque

# sys.stdin = open("input.txt", "r")


def flood(target_graph: list, start_row: int, start_col: int) -> None:
    dr = [-1, 0, 1, 0]
    dc = [0, -1, 0, 1]

    global r, c
    check = [[False for _ in range(c)] for _ in range(r)]
    q = deque()
    q.append((start_row, start_col, 0))
    check[start_row][start_col] = True
    while len(q) > 0:
        cr, cc, cur_count = q.popleft()

        if graph[cr][cc] == "D":
            continue

        target_graph[cr][cc] = cur_count

        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]

            if nr < 0 or nr >= r or nc < 0 or nc >= c:
                continue
            if check[nr][nc] or graph[nr][nc] == "X":
                continue

            next_count = cur_count + 1
            if water_graph[nr][nc] >= 0 and water_graph[nr][nc] <= next_count:
                continue
            check[nr][nc] = True
            q.append((nr, nc, next_count))


r, c = map(int, sys.stdin.readline().split())
graph = ["" for _ in range(r)]
water_graph = [[-1 for _ in range(c)] for _ in range(r)]
dochi_graph = [[-1 for _ in range(c)] for _ in range(r)]
water_pos = []
dochi_pos = None
beaver_pos = None
for i in range(r):
    graph[i] = sys.stdin.readline().strip()
    for j in range(c):
        if graph[i][j] == "S":
            dochi_pos = (i, j)
        elif graph[i][j] == "*":
            water_pos.append((i, j))
        elif graph[i][j] == "D":
            beaver_pos = (i, j)


for water in water_pos:
    flood(water_graph, water[0], water[1])
flood(dochi_graph, dochi_pos[0], dochi_pos[1])

dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]
answer = -1
for i in range(4):
    nr = beaver_pos[0] + dr[i]
    nc = beaver_pos[1] + dc[i]

    if nr < 0 or nr >= r or nc < 0 or nc >= c:
        continue
    if dochi_graph[nr][nc] >= 0:
        answer = (
            dochi_graph[nr][nc] + 1
            if answer < 0 or answer > dochi_graph[nr][nc] + 1
            else answer
        )
if answer < 0:
    answer = "KAKTUS"
print(answer)
