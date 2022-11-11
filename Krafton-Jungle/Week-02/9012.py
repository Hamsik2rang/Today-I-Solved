import sys

tc = int(input())

while tc > 0:
    tc -= 1
    ps = input()
    stk = 0
    is_vps = True
    for c in ps:
        if c == "(":
            stk += 1
        else:
            stk -= 1

        if stk < 0:
            is_vps = False
            break

    if stk != 0:
        is_vps = False

    print("YES" if is_vps else "NO")
