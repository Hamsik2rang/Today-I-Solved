n, k = map(int, input().split())
k_origin = k
num = input()
stk = []
for c in num:
    while len(stk) > 0 and k > 0 and stk[-1] < c:
        stk.pop()
        k -= 1
    stk.append(c)

while len(stk) > n - k_origin:
    stk.pop()

if len(stk) == 0:
    print(0)
else:
    print(int("".join(stk)))
