#!/usr/bin/python3
"""Log Parsing"""
import sys

# Initialize an empty list to store input lines
input = []

try:
    # Read lines from standard input and append them to the 'input' list
    for line in sys.stdin:
        input.append(line.strip())
except KeyboardInterrupt:
    pass  # Handle a KeyboardInterrupt (Ctrl+C) gracefully by doing nothing

# Define a list of error numbers
errornmbs = ["200", "301", "400", "401", "403", "404", "405", "500"]

# Initialize a list to count the occurrences of each error number
errorcount = [0, 0, 0, 0, 0, 0, 0, 0]

# Initialize counters for line count and file size
linecount = 0
filesize = 0

# Iterate through each line in the 'input' list
for line in input:
    try:
        # Increment the line count
        linecount += 1

        # Split the line into words
        line = line.split()

        # Check if the error number matches any in 'errornmbs'
        for i in range(8):
            if line[-2] == errornmbs[i]:
                errorcount[i] += 1

        # Add the file size (the last element) to 'filesize'
        filesize += int(line[-1])

        # Check if we've processed 10 lines or reached the end of the input
        if linecount % 10 == 0 or linecount == len(input):
            print("File size: ", filesize)
            for i in range(8):
                if errorcount[i] != 0:
                    print(f"{errornmbs[i]}: {errorcount[i]}")
    except IndexError:
        pass  # Handle an IndexError gracefully by doing nothing
    except KeyboardInterrupt:
        # Handle a KeyboardInterrupt by printing statistics and exiting
        print("File size: ", filesize)
        for i in range(8):
            if errorcount[i] != 0:
                print(f"{errornmbs[i]}: {errorcount[i]}")

# Exit the script with a status code of 0 (success)
sys.exit(0)
