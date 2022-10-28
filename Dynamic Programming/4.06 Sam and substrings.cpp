#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'substrings' function below.
#
# The function is expected to return an INTEGER.
# The function accepts STRING n as parameter.
#

def substrings(n):
    # Write your code here
    s = 0
    prev_sum = 0
    
    for i, d in enumerate(n):
        s_ = prev_sum * 10 + (i + 1) * int(d)
        s += s_
        prev_sum = s_
    return s % (10 ** 9 + 7)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = input()

    result = substrings(n)

    fptr.write(str(result) + '\n')

    fptr.close()

