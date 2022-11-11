from heapq import heappush, heappop
import sys

pq = []

n = int(sys.stdin.readline())
for i in range(n):
    cmd = int(sys.stdin.readline())
    if cmd == 0:
        if not pq:
            print(0)
        else:
            top = heappop(pq)
            print(-top)
    else:
        heappush(pq, -cmd)
