#!/usr/bin/python3
"""
Place N non-attacking queens on an N×N chessboard
"""
# pylint: disable=invalid-name
import sys


def is_safe(board, row, col, size):
    """
    Check if a queen can be placed at the given position.
    """
    # check row on left side
    for iy in range(col):
        if board[row][iy] == 1:
            return False

    ix, iy = row, col
    while ix >= 0 and iy >= 0:
        if board[ix][iy] == 1:
            return False
        ix -= 1
        iy -= 1

    jx, jy = row, col
    while jx < size and jy >= 0:
        if board[jx][jy] == 1:
            return False
        jx += 1
        jy -= 1

    return True


def solve(board, col, n, saved):
    """
    Solve N queens.
    """
    if col < n:
        for row in range(n):
            if is_safe(board, row, col, n):
                board[row][col] = 1
                if col == n - 1:
                    saved.append([row.copy() for row in board])
                    board[row][col] = 0
                    break
                solve(board, col + 1, n, saved)
                board[row][col] = 0


def print_solutions(solutions, size):
    """Prints N queens solutions."""
    new = []
    for sol in solutions:
        tmp = []
        for i, row in enumerate(sol):
            inner = []
            for j, num in enumerate(row):
                if num == 1:
                    inner.append(j)
                    inner.append(i)
            tmp.append(inner)
        new.append(tmp)
    for ans in new:
        print(ans)


def main():
    """
    Place N non-attacking queens on an N×N chessboard.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        return 1
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        return 1
    if n < 4:
        print("N must be at least 4")
        return 1

    board = [[0 for _ in range(n)] for _ in range(n)]
    saved = []
    solve(board, 0, n, saved)
    print_solutions(saved, n)



if __name__ == '__main__':
    sys.exit(main())
