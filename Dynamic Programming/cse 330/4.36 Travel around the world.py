#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'travelAroundTheWorld' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#  3. LONG_INTEGER c
#

def travelAroundTheWorld(a, b, c):
    # Write your code here
    total = 0
    n = len(a)
    city_num_to_validate = n
    for index in range(n-1, -1, -1):
        tank = 0
        is_valid = True
        for i in range(city_num_to_validate):
            curr_index = (index + i) % n
            tank += a[curr_index]
            if tank > c:
                tank = c
            tank -= b[curr_index]
            if tank < 0:
                is_valid = False
                break
        if is_valid:
            total += 1
            city_num_to_validate = 1
        elif city_num_to_validate < n:
            city_num_to_validate += 1
    return total

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    c = int(first_multiple_input[1])

    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    result = travelAroundTheWorld(a, b, c)

    fptr.write(str(result) + '\n')

    fptr.close()
