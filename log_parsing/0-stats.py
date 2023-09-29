#!/usr/bin/python3
"""Log Parsing"""
import sys

# Initialize an empty list to store input lines
input_lines = []

try:
    # Read lines from standard input and append them to the 'input_lines' list
    for line in sys.stdin:
        input_lines.append(line.strip())
except KeyboardInterrupt:
    pass  # Handle a KeyboardInterrupt (Ctrl+C) gracefully by doing nothing

# Define a list of error numbers
error_numbers = ["200", "301", "400", "401", "403", "404", "405", "500"]

# Initialize a list to count the occurrences of each error number
error_counts = [0, 0, 0, 0, 0, 0, 0, 0]

# Initialize counters for line count and file size
line_count = 0
file_size = 0

# Iterate through each line in the 'input_lines' list
for line in input_lines:
    try:
        # Increment the line count
        line_count += 1

        # Split the line into words
        line_parts = line.split()

        # Check if the error number matches any in 'error_numbers'
        for i in range(8):
            if line_parts[-2] == error_numbers[i]:
                error_counts[i] += 1

        # Add the file size (the last element) to 'file_size'
        file_size += int(line_parts[-1])

        # Check if we've processed 10 lines or reached the end of the input
        if line_count % 10 == 0 or line_count == len(input_lines):
            print("File size: {}".format(file_size))
            for i in range(8):
                if error_counts[i] != 0:
                    print("{}: {}".format(error_numbers[i], error_counts[i]))
    except IndexError:
        pass  # Handle an IndexError gracefully by doing nothing
    except KeyboardInterrupt:
        # Handle a KeyboardInterruptby printing statistics and exiting
        print("File size: {}".format(file_size))
        for i in range(8):
            if error_counts[i] != 0:
                print("{}: {}".format(error_numbers[i], error_counts[i]))

# Exit the script with a status code of 0 (success)
sys.exit(0)
