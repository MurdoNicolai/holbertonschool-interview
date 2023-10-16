#!/usr/bin/python3
""" conatinas validUTF8"""


def validUTF8(data):
    """ checs if data is a valid utf8"""
    print('{0:08b}'.format(127))
    if type(data) is not list:
        return False
    continuation = 0
    for num in data:
        num = num%256
        if continuation != 0:
            if num > 191 or num < 128: #over 1011 1111 or under 1000 0000
                return False
            else:
                continuation -= 1
        else:
            if num >= 128 and num <= 191: #under 1011 1111 and over 1000 0000
                return False
            if num >= 192: #over 1100 0000
                continuation += 1
            if num >= 224: #over 1110 0000
                continuation += 1
            if num >= 240: #over 1111 0000
                continuation += 1
    if continuation == 0:
        return True
    return False
