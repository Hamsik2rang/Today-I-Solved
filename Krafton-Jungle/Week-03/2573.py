import sys

sys.setrecursionlimit(10**5 * 2)
# sys.stdin = open("input.txt", "r")

n, m = map(int, sys.stdin.readline().split())


def dfs(row: int, col: int) -> None:
    check[row][col] = True
    dr = [-1, 0, 1, 0]
    dc = [0, -1, 0, 1]
    adj_sea_count = 0
    for i in range(4):
        nr = row + dr[i]
        nc = col + dc[i]
        if nr < 0 or nr >= n or nc < 0 or nc >= m:
            continue

        if not check[nr][nc] and graph[nr][nc] > 0:
            dfs(nr, nc)
        elif graph[nr][nc] == 0:
            adj_sea_count += 1

    next_iceberg_status.append([row, col, adj_sea_count])


graph = [[] for _ in range(n)]
for i in range(n):
    graph[i] = list(map(int, sys.stdin.readline().split()))

year = 0
while True:
    check = [[False for _ in range(m)] for _ in range(n)]
    next_iceberg_status = []
    dfs_count = 0

    for row in range(n):
        for col in range(m):
            if graph[row][col] > 0 and not check[row][col]:
                dfs(row, col)
                dfs_count += 1

    if dfs_count == 0:
        year = 0

    if dfs_count != 1:
        break

    for next_iceberg in next_iceberg_status:
        row, col, melted_height = next_iceberg
        next_height = graph[row][col] - melted_height
        next_height = 0 if next_height < 0 else next_height
        graph[row][col] = next_height

    next_iceberg_status.clear()
    year += 1


print(year)
