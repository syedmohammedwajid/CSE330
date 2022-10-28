 #!/bin/python3

import math

n = int(input())
A = list(map(int,input().split()))
T = [0]*n
MOD = 10**9 +7

def pow_mod(x, y):
    number = 1
    while y:
        if y & 1:
            number = number * x % MOD
        y >>= 1
        x = x * x % MOD
    return number

mem = pow_mod(2,n) + pow_mod(2,n-1)
ans = 0
k = 0
for i in range(1,math.ceil(n/2)+1):
    temp = mem - pow_mod(2,n-i) - pow_mod(2,i-1) 
    T[i-1] = temp
    T[n-i] = temp

# print(T)

for a in A:
    # print(k)
    ans = (ans + T[k]*a)%MOD
    k+=1
    
print(ans)
