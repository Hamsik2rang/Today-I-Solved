import sys

container = [0] * 2000000
fr = rear = 0


def push(x: int) -> None:
    global rear
    container[rear] = x
    rear += 1


def pop() -> int:
    global fr
    if empty():
        return -1
    x = container[fr]
    fr += 1
    return x


def empty() -> int:
    global fr
    global rear

    if fr >= rear:
        return 1
    return 0


def size() -> int:
    global fr
    global rear

    if empty():
        return 0
    return rear - fr


def front() -> int:
    global fr

    if empty():
        return -1
    return container[fr]


def back() -> int:
    global rear

    if empty():
        return -1
    return container[rear - 1]


n = int(sys.stdin.readline())
while n > 0:
    n -= 1
    input_list = list(sys.stdin.readline().split())
    if input_list[0] == "push":
        push(int(input_list[1]))
    elif input_list[0] == "pop":
        print(pop())
    elif input_list[0] == "front":
        print(front())
    elif input_list[0] == "back":
        print(back())
    elif input_list[0] == "size":
        print(size())
    else:
        print(empty())
