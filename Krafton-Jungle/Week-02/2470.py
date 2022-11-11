import sys


n = int(sys.stdin.readline())
sol = list(map(int, sys.stdin.readline().split()))
sol.sort()

left, right = 0, len(sol) - 1

min = 2_100_000_000
alcali = sol[left]
acid = sol[right]
while left < right:
    mix = sol[left] + sol[right]
    result = abs(mix)

    if min >= result:
        min = result
        alcali = sol[left]
        acid = sol[right]
    if mix == 0:
        break
    elif mix < 0:
        left += 1
    else:
        right -= 1

print(alcali, acid)
