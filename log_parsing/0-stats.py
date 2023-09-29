#!/usr/bin/python3
"""
    Write a script that reads stdin line by line and computes metrics:

    Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
    <status code> <file size> (if the format is not this one, the line must
    be skipped)
    After every 10 lines and/or a keyboard interruption (CTRL + C), print
    these statistics from the beginning:
        Total file size: File size: <total size>
        where <total size> is the sum of all previous <file size> (see
        input format above)
        Number of lines by status code:
            possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
            if a status code doesn’t appear or is not an integer, don’t print
            anything for this status code
            format: <status code>: <number>
            status codes should be printed in ascending order
"""
import sys

# Initialize an empty list to store input lines
input_lines = []
# Define a list of error numbers
error_numbers = ["200", "301", "400", "401", "403", "404", "405", "500"]

# Initialize a list to count the occurrences of each error number
error_counts = [0, 0, 0, 0, 0, 0, 0, 0]

# Initialize counters for line count and file size
line_count = 0
file_size = 0

try:
    for line in sys.stdin:
    # Read lines from standard input and append them to the 'input_lines' list
        input_lines.append(line.strip())
except KeyboardInterrupt:
    pass  # Handle a KeyboardInterrupt (Ctrl+C) gracefully by doing nothing

# Iterate through each line in the 'input_lines' list
for line in input_lines:
    try:
        # Increment the line count
        line_count += 1

        # Split the line into words
        line_parts = line.split()

        for i in range(8):
        # Check if the error number matches any in 'error_numbers'
            if line_parts[-2] == error_numbers[i]:
                error_counts[i] += 1

        # Add the file size (the last element) to 'file_size'
        file_size += int(line_parts[-1])

        if line_count % 10 == 0 or line_count == len(input_lines):
            print("File size: {}".format(file_size))
            for i in range(8):
            # Check if we've processed 10 lines or reached the end of the input
                if error_counts[i] != 0:
                    print("{}: {}".format(error_numbers[i], error_counts[i]))
    except IndexError:
        pass  # Handle an IndexError gracefully by doing nothing
    except KeyboardInterrupt:
        print("File size: {}".format(file_size))
        for i in range(8):
        # Handle a KeyboardInterruptby printing statistics and exiting
            if error_counts[i] != 0:
                print("{}: {}".format(error_numbers[i], error_counts[i]))

# Exit the script with a status code of 0 (success)
sys.exit(0)
