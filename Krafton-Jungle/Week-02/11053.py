import sys


def lower_bound(lst: list, target: int, left: int, right: int) -> int:
    ans = left
    while left <= right:
        mid = (left + right) // 2
        if lst[mid] < target:
            left = mid + 1
        else:
            ans = mid
            right = mid - 1

    return ans


n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
result = []
for num in lst:
    if len(result) == 0 or result[-1] < num:
        result.append(num)
    else:
        index = lower_bound(result, num, 0, len(result) - 1)
        result[index] = num

print(len(result))
