import sys

t = int(sys.stdin.readline())

for tc in range(t):
    n = int(sys.stdin.readline())
    applicant = []
    for i in range(n):
        a, b = map(int, sys.stdin.readline().split())
        applicant.append([a, b])

    applicant.sort()

    max = applicant[0][1]
    answer = 1
    for i in range(1, n):
        if applicant[i][1] > max:
            continue
        answer += 1
        max = applicant[i][1]
    print(answer)
