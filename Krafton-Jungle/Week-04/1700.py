import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
use_list = list(map(int, sys.stdin.readline().split()))

schedule_dict = dict()
multitab = [None for _ in range(n)]
index = 0
for i in range(len(use_list)):
    if use_list[i] not in schedule_dict:
        schedule_dict[use_list[i]] = deque()
    schedule_dict[use_list[i]].append(i)

answer = 0

for use in use_list:
    if use in multitab:
        schedule_dict[use].popleft()
        continue

    if index < len(multitab):
        multitab[index] = use
        index += 1
    else:
        max = 0
        max_index = 0
        for i in range(len(multitab)):
            if len(schedule_dict[multitab[i]]) == 0:
                max_index = i
                break

            if schedule_dict[multitab[i]][0] > max:
                max = schedule_dict[multitab[i]][0]
                max_index = i
        multitab[max_index] = use
        answer += 1

    schedule_dict[use].popleft()
print(answer)
