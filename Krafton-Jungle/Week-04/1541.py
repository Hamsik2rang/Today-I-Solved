import sys
import re

expression = sys.stdin.readline().strip()
num = list(map(int, re.split("[+|-]", expression)))
op = re.split("[0-9]", expression)

sum = num[0]
op_index, num_index = 0, 1
sub_flag = False
while op_index < len(op) and num_index < len(num):
    if not op[op_index]:
        op_index += 1
        continue

    if op[op_index] == "-":
        sub_flag = True
    if sub_flag:
        sum -= num[num_index]
    else:
        sum += num[num_index]

    op_index += 1
    num_index += 1

print(sum)
