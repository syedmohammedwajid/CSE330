import math
import os
import random
import re
import sys
 
#
# Complete the 'cost' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY B as parameter.
#
 
def cost(B):
    # Write your code here
    N = len(B)
    assert 1 <= N <= pow(10,5)
    assert all(1 <= b <= 100 for b in B)
 
    llen, rlen = 0, 0
    right_pos = B[0]
 
    for i in range(1,N):
 
        new_llen = rlen + (right_pos - 1)
        new_right_pos = B[i]
        new_rlen = max(
            llen + (new_right_pos - 1),
            rlen + abs(new_right_pos - right_pos))
 
        llen, rlen = new_llen, new_rlen
        right_pos = new_right_pos
 
    return max(llen, rlen)
 
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
 
    t = int(input().strip())
 
    for t_itr in range(t):
        n = int(input().strip())
 
        B = list(map(int, input().rstrip().split()))
 
        result = cost(B)
 
        fptr.write(str(result) + '\n')
 
    fptr.close()
