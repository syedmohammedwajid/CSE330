#!/bin/python3

mod = 10**9 + 7
A = [0,0,0,0,0,2,3,15,2,0]
B = [0,0,0,0,0,4,9,13,17,2]
results = [1,9,90,303,280,218,95,101,295]
for _ in range(int(input())):
   n = int(input())
   for i in range(len(A),n):
      A.append((2*(A[i-5] + B[i-5])) % mod)
      B.append((A[i-1] + A[i-5] + 2*B[i-5]) % mod)
   print(results[n] if n < 9 else
      (5*A[n-1] + 9*A[n-2] + 19*A[n-3] + 6*A[n-4] + 3*A[n-5]
      + 2*B[n-1] + 5*B[n-2] + 20*B[n-3] + 5*B[n-4] + 4*B[n-5]) % mod)
