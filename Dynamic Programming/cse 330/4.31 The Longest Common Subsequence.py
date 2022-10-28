#!/bin/python3

def backtrack(c, x, y, i=None, j=None):
    i = i if i is not None else len(x) - 1
    j = j if j is not None else len(y) - 1
    
    if i < 0 or j < 0:
        return []
    
    if x[i] == y[j]:
        return backtrack(c, x, y, i-1, j-1) + [x[i]]
    
    if c[i][j-1] > c[i-1][j]:
        return backtrack(c, x, y, i, j-1)
    
    return backtrack(c, x, y, i-1, j)

def lcs(x, y):
    c = [[0 for j in range(len(y) + 1)] for i in range(len(x) + 1)]
    for i in range(len(x)):
        for j in range(len(y)):
            if x[i] == y[j]:
                c[i][j] = c[i-1][j-1] + 1
            else:
                c[i][j] = max(c[i][j-1], c[i-1][j])
    return backtrack(c, x, y)
    return c[len(x)-1][len(y)-1]


    
if __name__ == '__main__':
    n, m = map(int, input().split())
    A, B = (list(map(int, input().split())) for i in range(2))
    result = lcs(A, B)
    print(' '.join(map(str, result)))
