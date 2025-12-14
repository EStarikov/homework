from itertools import combinations

def check(board, r, c):
    for i in range(n):
        for j in range(n):
            if board[i][c] == 1:
                return False
            if board[r][j] == 1:
                return False
            if (i - j == r - c or i + j == r + c) and board[i][j] == 1:
                return False
    return True

n = int(input())
answer = 0

coordinates = []
for i in range(n):
    for j in range(n):
        coordinates.append([i, j])  #генерация всех возможных координат для ферзя
var = combinations(coordinates, n)  #выбор n любых координат
for x in var:
    flag = True
    pool = [[0]*n for i in range(n)]
    for i in range(n):              #проверка что ферзи в данной выборке не бьют друг друга
        row, column = x[i][0], x[i][1]
        if not check(pool, row, column):
            flag = False
            break
        pool[row][column] = 1
    if flag == True:
        answer += 1
print(answer)