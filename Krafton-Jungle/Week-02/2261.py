import sys


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __le__(self, other):
        if self.x == other.x:
            return self.y <= other.y
        return self.x <= other.x

    def __lt__(self, other):
        if self.x == other.x:
            return self.y < other.y
        return self.x < other.x


def distance(p1: Point, p2: Point) -> int:
    return (p1.x - p2.x) ** 2 + (p1.y - p2.y) ** 2


def brute_force(a, start, end):
    ans = -1
    for i in range(start, end):
        for j in range(i + 1, end + 1):
            dist = distance(a[i], a[j])
            if ans == -1 or ans > dist:
                ans = dist
    return ans


def closest(point_list: list, start: int, end: int) -> int:
    n = end - start + 1
    if n <= 3:
        return brute_force(point_list, start, end)

    mid = (start + end) // 2
    left = closest(point_list, start, mid)
    right = closest(point_list, mid + 1, end)
    ans = min(left, right)
    min_candidate = []
    for i in range(start, end + 1):
        dist = point_list[i].x - point_list[mid].x
        if dist * dist < ans:
            min_candidate.append(point_list[i])

    min_candidate.sort(key=lambda p: (p.y, p.x))
    m = len(min_candidate)
    for i in range(m - 1):
        for j in range(i + 1, m):
            y = min_candidate[j].y - min_candidate[i].y
            if y * y < ans:
                dist = distance(min_candidate[i], min_candidate[j])
                if dist < ans:
                    ans = dist
            else:
                break
    return ans


n = int(input())
lst = [Point(*map(int, input().split())) for _ in range(n)]
lst.sort()
print(closest(lst, 0, n - 1))
