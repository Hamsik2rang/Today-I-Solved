n = int(input())
height = list(map(int, input().split()))
stk = [[100_000_001, 0]]
ans = []

for i in range(len(height)):
    while len(stk) != 0 and stk[-1][0] < height[i]:
        stk.pop()
    ans.append(stk[-1][1])
    stk.append([height[i], i + 1])

print(*ans)
