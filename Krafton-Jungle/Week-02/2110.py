import sys


def search(home: list, c: int, left: int, right: int) -> int:
    ans = left
    while left <= right:
        mid = (left + right) // 2
        diff = 0
        cnt = 1
        for i in range(1, len(home)):
            if cnt == c:
                break
            if diff + home[i] - home[i - 1] < mid:
                diff += home[i] - home[i - 1]
            else:
                cnt += 1
                diff = 0
        if cnt < c:
            right = mid - 1
        else:
            ans = mid
            left = mid + 1
    return ans


n, c = map(int, sys.stdin.readline().split())
home = [0] * n
for i in range(n):
    home[i] = int(sys.stdin.readline())

home.sort()

print(search(home, c, 1, home[-1] - home[0]))
