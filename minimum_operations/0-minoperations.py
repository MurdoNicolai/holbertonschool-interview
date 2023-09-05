#!/usr/bin/python3
""" contains minOperations"""


def minOperations(n):
    """ returns the minimum number of operations to be
    performed to get n h by using copy all and paste only"""
    dividends = []
    for i in range(2, n):
        if n % i == 0:
            dividends.append(i)
    if len(dividends) == 0:
        return ((n - 1) * 2)
    return (sum(dividends) - 1) * 2
