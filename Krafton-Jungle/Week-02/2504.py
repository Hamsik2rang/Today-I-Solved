string = input()
stk = []
ans = 0
for c in string:
    if c == "(" or c == "[":
        stk.append(c)
    else:
        cur = 0
        while len(stk) > 0 and type(stk[-1]) is int:
            cur += stk[-1]
            stk.pop()

        if len(stk) == 0:
            print(0)
            exit(0)

        if c == ")" and stk[-1] == "(":
            stk.pop()
            if cur == 0:
                stk.append(2)
            else:
                stk.append(cur * 2)
        elif c == "]" and stk[-1] == "[":
            stk.pop()
            if cur == 0:
                stk.append(3)
            else:
                stk.append(cur * 3)
        else:
            print(0)
            exit(0)

while len(stk) > 0 and type(stk[-1]) is int:
    ans += stk[-1]
    stk.pop()

if len(stk) != 0:
    print(0)
else:
    print(ans)
