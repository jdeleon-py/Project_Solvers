#import time
import numpy as np
import exception_handling as e
import time

def check_row(brd_, x_row, num):
    for i in range(0, 9):
        if brd_[x_row][i] == num:
            return False
    return True

def check_col(brd_, y_col, num):
    for i in range(0, 9):
        if brd_[i][y_col] == num:
            return False
    return True

def check_box(brd_, x_row, y_col, num):
    box_row = (x_row // 3) * 3
    box_col = (y_col // 3) * 3
    for i in range(0, 3):
        for j in range(0, 3):
            if brd_[box_row + i][box_col + j] == num:
                return False
    return True

def valid(x_row, y_col, num):
    global board
    if check_row(board, x_row, num) and check_col(board, y_col, num) and check_box(board, x_row, y_col, num):
        return True
    return False

def find_next():
    global board
    for i in range(0, 9):
        for j in range(0, 9):
            if board[i][j] == 0:
                return (i, j)
    return False

def solve():
    global board
    find = find_next()
    if not find:
        print(board)
        return True
    else:
        row, col = find

    for i in range(1, 10):
        if valid(row, col, i):
            board[row][col] = i
            print(board)
            print('\n')
            #time.sleep(0.1)

            if solve():
                return True

            board[row][col] = 0

    return False

# How could I include try/except blocks in here to produce error exceptions?

board = np.array([[1, 2, 3, 4, 5, 0, 7, 8, 9],
                  [0, 9, 0, 0, 0, 0, 0, 0, 0],
                  [0, 0, 8, 0, 0, 0, 0, 0, 0],
                  [0, 0, 0, 7, 0, 0, 0, 0, 0],
                  [0, 0, 0, 0, 6, 0, 0, 0, 0],
                  [0, 0, 0, 0, 0, 5, 0, 0, 0],
                  [0, 0, 0, 0, 0, 0, 4, 0, 0],
                  [0, 0, 0, 0, 0, 0, 0, 3, 0],
                  [0, 0, 0, 0, 0, 0, 0, 0, 2]])

solve()