from heapq import heappush, heappop
import sys


def set_mst_using_prim():
    global ans

    pq = []
    heappush(pq, [0, 0, 1])
    while len(pq) > 0:
        cur_cost, prev, cur = heappop(pq)
        mst[prev].append([cur, cur_cost])

        if check[cur]:
            continue
        check[cur] = True
        ans += cur_cost

        for i in range(len(graph[cur])):
            next, next_cost = graph[cur][i]
            if check[next]:
                continue
            heappush(pq, [next_cost, cur, next])


v, e = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(10001)]
mst = [[] for _ in range(10001)]
check = [False for _ in range(10001)]
ans = 0
for _ in range(e):
    src, dest, cost = map(int, sys.stdin.readline().split())
    graph[src].append([dest, cost])
    graph[dest].append([src, cost])

set_mst_using_prim()
print(ans)
