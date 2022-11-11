import sys


def lower_bound(lst: list, target: int, left: int, right: int) -> int:
    ans = right
    while left <= right:
        mid = (left + right) // 2
        if lst[mid] < target:
            left = mid + 1
        else:
            ans = mid
            right = mid - 1
    return ans


m, n, l = map(int, sys.stdin.readline().split())
hunter = list(map(int, sys.stdin.readline().split()))
hunter.sort()
ans = 0

for i in range(n):
    x, y = map(int, sys.stdin.readline().split())
    if y > l:
        continue
    index = lower_bound(hunter, x, 0, len(hunter) - 1)
    for shooter_index in [index - 1, index, index + 1]:
        if shooter_index < 0 or shooter_index >= m:
            continue
        dist = abs(hunter[shooter_index] - x) + y
        if dist <= l:
            ans += 1
            break

print(ans)
