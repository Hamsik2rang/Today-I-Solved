import sys

sys.setrecursionlimit(10**5)


class Node:
    def __init__(self, num):
        self.num = num
        self.left = None
        self.right = None

    def set_left(self, left):
        self.left = left

    def set_right(self, right):
        self.right = right


def pre_trav(node, num):
    if num < node.num:
        if not node.left:
            node.set_left(Node(num))
        else:
            pre_trav(node.left, num)
    elif num > node.num:
        if not node.right:
            node.set_right(Node(num))
        else:
            pre_trav(node.right, num)


def post_trav(node):
    if node.left:
        post_trav(node.left)
    if node.right:
        post_trav(node.right)
    print(node.num)


li = list()
while True:
    try:
        li.append(int(input()))
    except:
        break

root = Node(li[0])
for i in range(1, len(li)):
    pre_trav(root, li[i])
post_trav(root)
