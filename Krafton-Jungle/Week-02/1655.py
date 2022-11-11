from heapq import heappush, heappop
import sys

# sys.stdin = open("input.txt", "r")
max_heap, min_heap = [], []
n = int(sys.stdin.readline())

for _ in range(n):
    num = int(sys.stdin.readline())
    heappush(min_heap, num)

    while len(max_heap) < len(min_heap):
        heappush(max_heap, -heappop(min_heap))
    while len(max_heap) > 0 and len(min_heap) > 0 and -max_heap[0] > min_heap[0]:
        temp = -heappop(max_heap)
        heappush(max_heap, -heappop(min_heap))
        heappush(min_heap, temp)

    print(-max_heap[0])
