#!/usr/bin/python3
"""
    contains pascal trianle function
"""

def pascal_triangle(n):
    """
    Function that generates and prints Pascal's triangle up to the nth row.

    Returns:
        List of lists of integers representing Pascal’s triangle of n.
        Returns an empty list if n <= 0.
    """
    if n <= 0:
        return []
    triangle = [[1]]

    for i in range(1, n):
        row = [1]
        for j in range(1, i):
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
        row.append(1)
        triangle.append(row)

    return triangle
