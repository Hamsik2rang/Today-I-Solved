import sys
from heapq import heappush, heappop


def dijkstra(src: int, dest: int) -> int:
    global n
    pq = []
    dist = [0x7FFFFFFF for i in range(n + 1)]
    dist[src] = 0
    heappush(pq, [dist[src], src])

    while len(pq) > 0:
        cur_cost, cur = heappop(pq)

        if dist[cur] < cur_cost:
            continue

        for next, next_cost in graph[cur]:
            if dist[next] <= cur_cost + next_cost:
                continue
            dist[next] = cur_cost + next_cost
            heappush(pq, [dist[next], next])

    return dist[dest]


n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
graph = [[] for i in range(n + 1)]
for i in range(m):
    src, dest, cost = map(int, sys.stdin.readline().split())
    graph[src].append([dest, cost])


src, dest = map(int, sys.stdin.readline().split())
print(dijkstra(src, dest))
