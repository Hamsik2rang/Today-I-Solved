import sys

# 모듈러 정리
# (A+B)%C = (A%C + B%C)%C
# (A*B)%C = (A%C * B&C)&C


def square_matrix(matrix1: list, matrix2: list, length: int) -> list:
    result = [[0 for i in range(length)] for j in range(length)]
    for row in range(length):
        for col in range(length):
            for k in range(length):
                result[row][col] += matrix1[row][k] * matrix2[k][col]
    return result


def divide(matrix: list, length: int) -> list:
    DIV = 1000
    for i in range(length):
        for j in range(length):
            matrix[i][j] %= DIV

    return matrix


def partition(exp: int, matrix: list, length: int) -> list:
    if exp == 1:
        return divide(matrix, length)
    if exp % 2 == 1:
        result = partition((exp - 1) // 2, matrix, length)
        return divide(
            square_matrix(square_matrix(result, result, length), matrix, length), length
        )
    else:
        result = partition(exp // 2, matrix, length)
        return divide(square_matrix(result, result, length), length)


n, b = map(int, sys.stdin.readline().split())
matrix = [[0 for i in range(n)] for j in range(n)]

for i in range(n):
    matrix[i] = list(map(int, sys.stdin.readline().split()))

ans = partition(b, matrix, n)
for row in ans:
    print(*row)
