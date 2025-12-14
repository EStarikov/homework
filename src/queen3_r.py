from itertools import permutations


def check(board, r, c):
    for i in range(r):
        if board[i] == c:  # проверка столбца
            return False
        if abs(board[i] - c) == abs(i - r):  # проверка диагонали
            return False
    return True


answer = 0
n = int(input())
col = [i for i in range(n)]
# получаем все расстановки, но теперь ряд это индекс элемента, а столбец - его значение
p = permutations(col)
for x in p:
    flag = True
    for i in range(n):
        r, c = i, x[i]
        if not check(x, r, c):
            flag = False
            break
    if flag:
        answer += 1
print(answer)
