#!/bin/python3

import math

def solve(a):
    s = sum(a)
    if s % 2:
        return 0
    s //= 2
    t = 0
    for i in range(len(a)):
        t += a[i]
        if t == s:
            #print(sum(a[:i + 1]), sum(a[i + 1:]))
            return 1 + max(solve(a[:i + 1]), solve(a[i + 1:]))
        if t > s:
            return 0
        
def solve0(n):
    return n - 1

t = int(input().strip())
for test in range(t):
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    if sum(a) == 0:
        print(solve0(n))
    else:
        print(solve(a))
