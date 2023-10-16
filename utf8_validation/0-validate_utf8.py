#!/usr/bin/python3
""" conatinas validUTF8"""


def validUTF8(data):
    """ checs if data is a valid utf8"""
    if type(data) is not int:
        return False
    for num in data:
        if num > 255:
            return False
    return True
