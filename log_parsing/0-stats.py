#!/usr/bin/python3
"""Log Parsing"""
import sys


input = []
try:
    for line in sys.stdin:
        input.append(line.strip())
except KeyboardInterrupt:
    pass
errornmbs = ["200", "301", "400", "401", "403", "404", "405", "500"]
errorcount = [0, 0, 0, 0, 0, 0, 0, 0]
linecount = 0
filesize = 0
for line in input:
    try:
        linecount += 1
        line = line.split()
        for i in range(8):
            if line[-2] == errornmbs[i]:
                errorcount[i] += 1
        filesize += int(line[-1])
        if linecount % 10 == 0 or linecount == len(input):
            print("File size: ", filesize)
            for i in range(8):
                if errorcount[i] != 0:
                    print(f"{errornmbs[i]}: {errorcount[i]}")
    except IndexError:
        pass
    except KeyboardInterrupt:
        print("File size: ", filesize)
        for i in range(8):
            if errorcount[i] != 0:
                print(f"{errornmbs[i]}: {errorcount[i]}")
sys.exit(0)
