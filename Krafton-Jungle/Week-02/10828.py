import sys

t = int(input())
stk = []

for i in range(t):
    command = list(sys.stdin.readline().split())
    if len(command) == 1:
        if command[0] == "top":
            if len(stk) == 0:
                print(-1)
            else:
                print(stk[-1])
        elif command[0] == "size":
            print(len(stk))
        elif command[0] == "empty":
            if len(stk) == 0:
                print(1)
            else:
                print(0)
        elif command[0] == "pop":
            if len(stk) == 0:
                print(-1)
            else:
                print(stk[-1])
                stk.pop()

    else:
        stk.append(int(command[1]))
