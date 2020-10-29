#!/usr/bin/python3
"""Place N non-attacking queens on an N×N chessboard."""
# pylint: disable=invalid-name
import sys


def solve_n_queens(board, row, n_queens, saved):
    """Find all N-queens solutions."""
    if row < n_queens:
        for col in range(n_queens):
            if queen_is_valid(board, row, col, n_queens):
                board[row][col] = True
                if row == n_queens - 1:
                    saved.append([row.copy() for row in board])
                    board[row][col] = False
                    break
                solve_n_queens(board, row + 1, n_queens, saved)
                board[row][col] = False


def queen_is_valid(board, row, col, n_queens):
    """Check if a queen can be placed at a given position."""
    if any(board[row][col] for row in range(row)):
        return False
    diag = zip(reversed(range(row)), reversed(range(col)))
    if any(board[row][col] for row, col in diag):
        return False
    diag = zip(reversed(range(row)), range(col + 1, n_queens))
    if any(board[row][col] for row, col in diag):
        return False
    return True


def main():
    """Parse arguments and solve N-queens."""
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
