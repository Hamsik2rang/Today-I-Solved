import sys


class Node:
    def __init__(self):
        self.value = None
        self.left = None
        self.right = None


node_list = [Node() for i in range(26)]


def pre_traverse(node: Node) -> None:
    print(node.value, end="")
    if node.left != None:
        pre_traverse(node_list[node.left])
    if node.right != None:
        pre_traverse(node_list[node.right])


def in_traverse(node: Node) -> None:
    if node.left != None:
        in_traverse(node_list[node.left])
    print(node.value, end="")
    if node.right != None:
        in_traverse(node_list[node.right])


def post_traverse(node: Node) -> None:
    if node.left != None:
        post_traverse(node_list[node.left])
    if node.right != None:
        post_traverse(node_list[node.right])
    print(node.value, end="")


n = int(sys.stdin.readline())
for _ in range(n):
    parent, left, right = sys.stdin.readline().split()
    if left == ".":
        left = None
    else:
        left = ord(left) - ord("A")
    if right == ".":
        right = None
    else:
        right = ord(right) - ord("A")

    node_list[ord(parent) - ord("A")].value = parent
    node_list[ord(parent) - ord("A")].left = left
    node_list[ord(parent) - ord("A")].right = right

pre_traverse(node_list[0])
print()
in_traverse(node_list[0])
print()
post_traverse(node_list[0])
