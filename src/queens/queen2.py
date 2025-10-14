def check(board, r, c):
    for i in range(r):
        if board[i] == c:  #проверка столбца
            return False
        if abs(board[i] - c) == abs(i - r):   #проверка диагонали
            return False
    return True

def next_row(r, current_board, n):
    global k
    if r == n:
        k += 1
        return
    for c in range(n):
        if check(current_board, r, c):
            current_board[r] = c
            next_row(r + 1, current_board, n)
k = 0
n = int(input())
next_row(0, [-1]*n, n)
print(k)