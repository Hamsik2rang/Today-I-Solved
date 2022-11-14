import sys
from collections import deque


def bfs() -> int:
    dr = [-1, 0, 1, 0]
    dc = [0, -1, 0, 1]

    answer = -1
    check = [[-1 for _ in range(n)] for _ in range(n)]
    q = deque()
    q.append((0, 0, 0))
    check[0][0] = 0
    while len(q) > 0:
        cr, cc, cur_count = q.popleft()
        if cr == n - 1 and cc == n - 1:
            answer = cur_count if answer < 0 or cur_count < answer else answer

        for i in range(4):
            nr = cr + dr[i]
            nc = cc + dc[i]

            if nr < 0 or nr >= n or nc < 0 or nc >= n:
                continue
            next_count = cur_count
            if graph[nr][nc] == "0":
                next_count += 1
            if check[nr][nc] >= 0 and check[nr][nc] <= next_count:
                continue
            check[nr][nc] = next_count
            q.append((nr, nc, next_count))

    return answer


n = int(sys.stdin.readline())
graph = ["" for _ in range(n)]
for i in range(n):
    graph[i] = sys.stdin.readline().strip()

answer = bfs()
print(answer)
