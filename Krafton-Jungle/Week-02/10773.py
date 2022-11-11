k = int(input())
stk = []
while k > 0:
    k -= 1
    n = int(input())
    if n == 0:
        stk.pop()
    else:
        stk.append(n)

ans = 0
for num in stk:
    ans += num

print(ans)
