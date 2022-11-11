import sys


class Info:
    def __init__(self, pos: int, is_open: bool, is_tangent: bool):
        self.pos = pos
        self.is_open = is_open
        self.is_tangent = is_tangent


n = int(sys.stdin.readline())
info_list = []
for _ in range(n):
    center, radius = map(int, sys.stdin.readline().split())
    info_list.append(Info(center - radius, True, False))
    info_list.append(Info(center + radius, False, False))

info_list.sort(key=lambda x: (x.pos, x.is_open))

stk = []
ans = 1
for i in range(len(info_list)):
    if len(stk) == 0:
        stk.append(info_list[i])
        last = info_list[i].pos
        continue

    # 새 원이 시작되는 지점
    if info_list[i].is_open == True:
        if info_list[i].pos == stk[-1].pos:
            stk[-1].is_tangent = True
        stk.append(info_list[i])

    # 임의의 원이 끝나는 지점
    else:
        if stk[-1].is_tangent:
            ans += 2
        else:
            ans += 1
        stk.pop()

        if i < len(info_list) - 1:
            if info_list[i].pos != info_list[i + 1].pos:
                stk[-1].is_tangent = False
print(ans)
