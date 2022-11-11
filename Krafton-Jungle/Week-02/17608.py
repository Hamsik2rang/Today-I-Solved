tc = int(input())

stk = []
while tc > 0:
    tc -= 1
    num = int(input())
    while len(stk) > 0 and stk[-1] <= num:
        stk.pop()

    stk.append(num)

print(len(stk))
