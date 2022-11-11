import sys


def search(tree_list: list, m: int, low: int, high: int) -> int:
    ans = low
    while low <= high:
        length_cut = (low + high) // 2
        length_sum = 0
        for tree in tree_list:
            length_sum += tree - length_cut if tree - length_cut > 0 else 0

        if length_sum < m:
            high = length_cut - 1
        else:
            ans = length_cut
            low = length_cut + 1
    return ans


n, m = map(int, sys.stdin.readline().split())
tree_list = list(map(int, sys.stdin.readline().split()))

right = max(tree_list)
ans = search(tree_list, m, 0, right)
print(ans)
