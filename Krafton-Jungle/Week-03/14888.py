import sys

sys.setrecursionlimit(10**5 * 2)


def brute_force(cur_num: int, index: int, n: int):
    global max_num, min_num
    if index == n - 1:
        max_num = max(max_num, cur_num)
        min_num = min(min_num, cur_num)
        return

    for op in range(4):
        if op_list[op] == 0:
            continue

        last_num = cur_num
        if op == 0:
            cur_num += num_list[index + 1]
        elif op == 1:
            cur_num -= num_list[index + 1]
        elif op == 2:
            cur_num *= num_list[index + 1]
        elif op == 3:
            if cur_num < 0:
                cur_num = (abs(cur_num) // num_list[index + 1]) * -1
            else:
                cur_num //= num_list[index + 1]
        op_list[op] -= 1
        brute_force(cur_num, index + 1, n)
        cur_num = last_num
        op_list[op] += 1


n = int(sys.stdin.readline())
num_list = list(map(int, sys.stdin.readline().split()))
op_list = list(map(int, sys.stdin.readline().split()))


max_num = -1_000_000_001
min_num = 1_000_000_001

brute_force(num_list[0], 0, n)
print(max_num)
print(min_num)
