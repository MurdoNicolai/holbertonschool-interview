#!/usr/bin/python3
""" contains minOperations"""


def minOperations(n):
    """ returns the minimum number of operations to be
    performed to get n h by using copy all and paste only"""
    dividends = []
    i = 2
    while n > 1:
        if n % i == 0:
            dividends.append(i)
            n = n/i
        else:
            i += 1
    return sum(dividends)
