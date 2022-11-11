import sys


def get_mid_area(height: list, left: int, mid: int, right: int) -> int:
    lp = rp = mid
    cur_height = height[mid]
    ans = cur_height * 1
    while lp > left and rp < right:
        next_height = 0
        if height[lp - 1] < height[rp + 1]:
            rp += 1
            next_height = height[rp]
        else:
            lp -= 1
            next_height = height[lp]
        cur_height = min(cur_height, next_height)
        ans = max(ans, cur_height * (rp - lp + 1))

    while lp > left:
        lp -= 1
        cur_height = min(cur_height, height[lp])
        ans = max(ans, cur_height * (rp - lp + 1))
    while rp < right:
        rp += 1
        cur_height = min(cur_height, height[rp])
        ans = max(ans, cur_height * (rp - lp + 1))

    return ans


def solution(height: list, left: int, right: int) -> int:
    if left == right:
        return height[left]

    mid = (left + right) // 2
    left_area = solution(height, left, mid)
    right_area = solution(height, mid + 1, right)
    mid_area = get_mid_area(height, left, mid, right)

    ans = max([left_area, mid_area, right_area])
    return ans


while True:
    lst = list(map(int, sys.stdin.readline().split()))
    if lst[0] == 0:
        break

    height = lst[1:]
    print(solution(height, 0, len(height) - 1))
