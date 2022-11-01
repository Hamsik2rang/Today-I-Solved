import sys

ans = []


# sys.stdin = open("input.txt", "r")


def kmp(txt: str, pat: str) -> int:
    pt = 1
    pp = 0
    skip = [0] * (len(pat) + 1)

    skip[pt] = 0
    while pt != len(pat):
        if pat[pt] == pat[pp]:
            pt += 1
            pp += 1
            skip[pt] = pp
        elif pp == 0:
            pt += 1
            skip[pt] = pp
        else:
            pp = skip[pp]

    pt = pp = 0
    while pt != len(txt) and pp != len(pat):
        if txt[pt] == pat[pp]:
            pt += 1
            pp += 1
        elif pp == 0:
            pt += 1
        else:
            pp = skip[pp]

        if pp == len(pat):
            ans.append(pt - pp + 1)
            pp = skip[pp]

    return pt - pp if pp == len(pat) else -1


s1 = input()
s2 = input()
idx = kmp(s1, s2)
print(len(ans))
for i in ans:
    print(i)
