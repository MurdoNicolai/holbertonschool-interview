#!/usr/bin/python3
""" conatinas validUTF8"""


def validUTF8(data):
    """ checs if data is a valid utf8"""
    if type(data) is not list:
        return False
    continuation = 0
    for num in data:
        if num > 511: #over 1111 1111
            return False
        if continuation != 0:
            if num >= 383 or num < 256: #over 1011 1111 or under 1000 0000
                return False
            else:
                conitnuation -= 1
        else:
            if num >= 256 and num < 383: #under 1011 1111 and over 1000 0000
                return False
            if num >= 383: #over 1100 0000
                continuation += 1
            if num >= 447: #over 1110 0000
                continuation += 1
            if num >= 479: #over 1111 0000
                continuation += 1
    if continuation == 0:
        return True
    return False
