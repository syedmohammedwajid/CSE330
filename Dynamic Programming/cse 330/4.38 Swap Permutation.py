#!/bin/python3

import sys
import math

def adjSwaps(n,k):
    if k==0:
        return 1
    else:
        #n==2:
        cntksteps = [1]*(k+1)
        #n>2:
        tmp = [0]*(k+1)
        for i in range(3,n+1):
            #0...i-1
            prefixSum = 0
            for j in range(min(i,k+1)):
                prefixSum+=cntksteps[j]
                prefixSum%=1000000007
                tmp[j] = prefixSum
            #i...k
            for j in range(i,k+1):
                prefixSum+=cntksteps[j]
                prefixSum-=cntksteps[j-i]
                tmp[j] = prefixSum
            for j in range(k+1):
                cntksteps[j] = tmp[j]
            #print(cntksteps)
        return cntksteps[k]%1000000007

def anySwaps(n,k):
    if k==0:
        return 1
    elif n<=k:
        return math.factorial(n)%1000000007
    else:

        tmp = [0]*(k+1)
        #n==2:
        cntksteps = [2]*(k+1)
        cntksteps[0] = 1
        #n>2:
        for i in range(3,n+1):
            #if i<k:
                #cntksteps[i] = cntksteps[i-1]*i
            for j in range(1,k+1):
                tmp[j] = (cntksteps[j]+(i-1)*cntksteps[j-1])%1000000007
            for j in range(1,k+1):
                cntksteps[j] = tmp[j]
            #cntksteps[0] = 1
            #print(cntksteps)
        return cntksteps[k]%1000000007
    
f = sys.stdin
tmp = f.readline().split()
n = int(tmp[0])
k = int(tmp[1])
print(adjSwaps(n,k), anySwaps(n,k))
