#!/bin/python3

N = int(input())

for n in range(N):
    input()
    hps = sorted(list(map(int, input().split())))
    s = 1
    total = sum(hps)
    for hp in hps:
        if (s+1) * (total - hp) <= s * total:
            break
        s += 1
        total -= hp
    print(s * total)
