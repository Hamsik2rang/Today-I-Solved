import sys


a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()
memo = [[0 for _ in range(len(b))] for _ in range(len(a))]

for i in range(len(a)):
    for j in range(len(b)):
        if a[i] == b[j]:
            last_match = 0 if i - 1 < 0 or j - 1 < 0 else memo[i - 1][j - 1]
            memo[i][j] = last_match + 1
        else:
            last_i_match = 0 if i - 1 < 0 else memo[i - 1][j]
            last_j_match = 0 if j - 1 < 0 else memo[i][j - 1]
            memo[i][j] = max(last_i_match, last_j_match)
print(memo[len(a) - 1][len(b) - 1])
