#!/usr/bin/python3
"""Provide a function to perform a right rotation of a square matrix"""


def rotate_2d_matrix(matrix):
    """
    Perform an in-place right rotation of a square matrix.
    Arguments:
        matrix: N x N matrix
    """
    if not isinstance(matrix, list):
        raise TypeError("'matrix' must be a list")
    if not all(isinstance(row, list) for row in matrix):
        raise TypeError("'matrix' must be a list of lists")
    if not all(len(row) == len(matrix) for row in matrix):
        raise TypeError("'matrix' must be square")
    dim = len(matrix)
    for row in range(0, dim // 2):
        for col in range(row, dim - row - 1):
            temp = matrix[row][col]
            matrix[row][col] = matrix[dim - col - 1][row]
            matrix[dim - col - 1][row] = matrix[dim - row - 1][dim - col - 1]
            matrix[dim - row - 1][dim - col - 1] = matrix[col][dim - row - 1]
            matrix[col][dim - row - 1] = temp
