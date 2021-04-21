n = int(input())
row = [list(map(int, input().split())) for _ in range(n)]
memo = [[0] * i for i in range(1, n + 1)]

memo[0][0] = row[0][0]

for i in range(1, n):
    for j in range(0, i + 1):
        if j == i:
            memo[i][j] = memo[i - 1][j - 1] + row[i][j]
        elif j == 0:
            memo[i][j] = memo[i - 1][j] + row[i][j]
        else:
            memo[i][j] = (
                memo[i - 1][j - 1] + row[i][j]
                if memo[i - 1][j - 1] > memo[i - 1][j]
                else memo[i - 1][j] + row[i][j]
            )

print(max(memo[n - 1]))
