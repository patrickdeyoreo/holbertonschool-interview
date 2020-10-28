#!/usr/bin/python3
"""
Place N non-attacking queens on an N×N chessboard.
"""
# pylint: disable=invalid-name
import sys


def solve_n_queens(board, col, n_queens, saved):
    """
    Solve N-queens.
    """
    if col < n_queens:
        for row in range(n_queens):
            if queen_is_valid(board, row, col, n_queens):
                board[row][col] = True
                if col == n_queens - 1:
                    saved.append([row.copy() for row in board])
                    board[row][col] = False
                    break
                solve_n_queens(board, col + 1, n_queens, saved)
                board[row][col] = False


def queen_is_valid(board, row, col, n_queens):
    """
    Check if a queen can be placed at the given position.
    """
    if any(board[row][x] for x in range(col)):
        return False

    diag = zip(reversed(range(row)), reversed(range(col)))
    if any(board[y][x] for y, x in diag):
        return False

    diag = zip(range(row + 1, n_queens), reversed(range(col)))
    if any(board[y][x] for y, x in diag):
        return False

    return True


def main():
    """
    Parse arguments and solve N-queens puzzle.
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        return 1
    try:
        n_queens = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        return 1
    if n_queens < 4:
        print("N must be at least 4")
        return 1

    board = [[False for _ in range(n_queens)] for _ in range(n_queens)]
    saved = []
    solve_n_queens(board, 0, n_queens, saved)
    for board in saved:
        print([[x, y]
               for y, row in enumerate(board)
               for x, pos in enumerate(row) if pos])
    return 0


if __name__ == '__main__':
    sys.exit(main())
