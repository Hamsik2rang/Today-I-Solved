import sys
from collections import deque


class Node:
    def __init__(self):
        self.child = []
        self.count = 0


n = int(sys.stdin.readline())
m = int(sys.stdin.readline())


def topological_sort(x: int) -> None:
    q = deque()
    q.append(x)
    node_list[x].count = 1
    while len(q) > 0:
        cur = q.popleft()
        for child, needs in node_list[cur].child:
            node_list[child].count += node_list[cur].count * needs
            parent_count[child] -= 1
            if parent_count[child] == 0:
                q.append(child)


node_list = [Node() for _ in range(n + 1)]
parent_count = [0 for _ in range(n + 1)]
answer = []

for _ in range(m):
    x, y, k = map(int, sys.stdin.readline().split())
    node_list[x].child.append([y, k])
    parent_count[y] += 1

topological_sort(n)
for i in range(1, n + 1):
    if len(node_list[i].child) == 0:
        print(i, node_list[i].count)
