from collections import deque

n, k = map(int, input().split())

q = deque()
for i in range(1, n + 1):
    q.append(i)
ans = []

while len(q) > 0:
    for i in range(k - 1):
        q.append(q.popleft())
    ans.append(q.popleft())

print("<", end="")
for i in range(len(ans) - 1):
    print(ans[i], end=", ")
print(ans[-1], end="")
print(">")
