from heapq import heappush, heappop
import sys

n = int(sys.stdin.readline())
heap = []

for _ in range(n):
    num = int(sys.stdin.readline())
    heappush(heap, num)


ans = 0
while len(heap) > 1:
    l, r = heappop(heap), heappop(heap)
    ans += l + r
    heappush(heap, l + r)

print(ans)
