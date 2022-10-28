a, b, n = [int(x) for x in input().split(" ")]

if n == 0:
    print(a)
if n == 1:
    print(b)

for _ in range(n-2):
    a, b = b, b*b + a
    
print(b)
