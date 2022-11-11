from heapq import heappush, heappop
import sys

n = int(sys.stdin.readline())
info = []
heap = []
for _ in range(n):
    start, end = map(int, sys.stdin.readline().split())
    if start > end:
        start, end = end, start
    info.append([start, end])

info.sort(key=lambda x: x[1])

d = int(sys.stdin.readline())
ans = 0
for start, end in info:
    while len(heap) > 0 and heap[0] < end - d:
        heappop(heap)
    if end - d <= start:
        heappush(heap, start)
    ans = max(ans, len(heap))

print(ans)
