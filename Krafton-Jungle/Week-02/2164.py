from collections import deque

n = int(input())
q = deque()

for i in range(1, n + 1):
    q.append(i)

cmd = True
while len(q) > 1:
    if cmd:
        q.popleft()
    else:
        q.append(q.popleft())
    cmd ^= True
print(q[0])
