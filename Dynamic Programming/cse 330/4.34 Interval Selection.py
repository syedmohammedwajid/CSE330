#!/bin/python3

t = int(input())
for _ in range(t):
  n = int(input())
  I = []
  for _ in range(n):
    a, b = list(map(int, input().split()))
    I.append((a, b))
  I.sort(key = lambda x: (x[1], x[0]))
  temp = -1
  lasta = 0
  lastb = 0
  res = 0
  for a, b in I:
    if a>lastb:
      res+=1
      lasta = a
      lastb = b
    elif a>temp:
      res+=1
      temp = lastb
      lasta = a
      lastb = b
  print(res)

 
