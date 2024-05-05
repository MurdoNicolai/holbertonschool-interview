#!/usr/bin/python3
"""
    Function that generates and prints Pascal's triangle up to the nth row.

    Returns:
        List of lists of integers representing Pascal’s triangle of n.
        Returns an empty list if n <= 0.
"""

def pascal_triangle(n):
    # Check if n is less than or equal to 0
    if n <= 0:
        return []

    # Initialize Pascal's triangle with the first row
    triangle = [[1]]

    # Generate each row of Pascal's triangle up to the nth row
    for i in range(1, n):
        row = [1]  # First element of each row is always 1
        for j in range(1, i):
            # Calculate the value for the current position in the triangle
            row.append(triangle[i - 1][j - 1] + triangle[i - 1][j])
        row.append(1)  # Last element of each row is always 1
        triangle.append(row)

    return triangle
