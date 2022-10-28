#!/bin/python3

s = input()
p = [[0] * len(s) for _ in range(len(s))]
for i in range(len(s)): p[i][i] = 1
for k in range(2, len(s) + 1):
    for i in range(len(s) - k + 1):
        j = i + k - 1
        if s[i] == s[j]:
            p[i][j] = 2 + (0 if k == 2 else p[i + 1][j - 1])
        else:
            p[i][j] = max(p[i][j - 1], p[i + 1][j])
print(max(p[0][i] * p[i + 1][-1] for i in range(len(s) - 1)))
