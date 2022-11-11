import sys


def binary_search(li: list, start: int, end: int, target: int) -> int:
    while start <= end:
        mid = (start + end) // 2
        if li[mid] < target:
            start = mid + 1
        elif li[mid] > target:
            end = mid - 1
        else:
            return 1
    return 0


n = int(sys.stdin.readline())
li = list(map(int, sys.stdin.readline().split()))
li.sort()

m = int(sys.stdin.readline())
tar = list(map(int, sys.stdin.readline().split()))

for i in tar:
    print(binary_search(li, 0, n - 1, i))
