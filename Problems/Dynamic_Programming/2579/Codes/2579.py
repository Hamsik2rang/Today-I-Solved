memo = {}
score = []


def solution(n, is_stepped=False):
    


n = int(input())

for _ in range(n):
    step = int(input())
    score.append(step)

print(solution(n - 1))
