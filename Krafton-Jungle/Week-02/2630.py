import sys


def solution(graph: list, row, col, n) -> None:
    flag = graph[row][col]
    have_to_divide = False
    for r in range(row, row + n):
        for c in range(col, col + n):
            if graph[r][c] != flag:
                have_to_divide = True
                break
        if have_to_divide:
            break

    if have_to_divide:
        solution(graph, row, col, n // 2)
        solution(graph, row, col + n // 2, n // 2)
        solution(graph, row + n // 2, col, n // 2)
        solution(graph, row + n // 2, col + n // 2, n // 2)
    else:
        ans[flag] += 1


n = int(sys.stdin.readline())
graph = [[0 for i in range(n)] for j in range(n)]
ans = [0, 0]

for i in range(n):
    graph[i] = list(map(int, sys.stdin.readline().split()))

solution(graph, 0, 0, n)
print(*ans)
