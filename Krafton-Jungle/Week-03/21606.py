import sys

sys.setrecursionlimit(10**5 * 2)


def dfs(x: int) -> int:
    global s
    check[x] = True
    count = 0
    for next in graph[x]:
        if not check[next] and s[next - 1] == "0":
            count += dfs(next)

        if s[next - 1] == "1":
            count += 1
    return count


answer = 0
n = int(sys.stdin.readline())
s = sys.stdin.readline().strip()
graph = [[] for _ in range(n + 1)]
check = [False for _ in range(n + 1)]


for _ in range(n - 1):
    src, dest = map(int, sys.stdin.readline().split())
    graph[src].append(dest)
    graph[dest].append(src)
    if s[src - 1] == "1" and s[dest - 1] == "1":
        answer += 2

for i in range(1, n + 1):
    if not check[i] and s[i - 1] == "0":
        count = dfs(i)
        answer += count * (count - 1)
print(answer)
