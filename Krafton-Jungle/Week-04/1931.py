import sys

n = int(sys.stdin.readline())
schedule = []
for i in range(n):
    begin, end = map(int, sys.stdin.readline().split())
    schedule.append([begin, end])

schedule.sort(key=lambda x: (x[1], x[0]))

answer = 0
cur_end = 0

for i in range(0, n):
    if schedule[i][0] < cur_end:
        continue
    answer += 1
    cur_end = schedule[i][1]

print(answer)
