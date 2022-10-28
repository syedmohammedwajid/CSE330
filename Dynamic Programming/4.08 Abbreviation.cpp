def recurse(a,b):
    if len(a) < len(b):
        return False
    if len(b) == 0:
        return a.islower()
    if a.upper() == b:
        return True
    if a[0].isupper():
        if a[0] == b[0]:
            return recurse(a[1:],b[1:])
        else:
            return False
    else:
        if a[0].upper() != b[0]:
            return recurse(a[1:],b)
        else:
            return (recurse(a[1:],b[1:]) or recurse(a[1:],b))

def solveProblem():
    a = input()
    b = input()
    x = recurse(a,b)
    if x:
        print('YES')
    else:
        print('NO')

T = int(input())
for t in range(T):
    solveProblem()
