#!/bin/python3

mod = 1000000007
num_cities = int(input().strip())

roads = [None]+[list() for _ in range(num_cities)]
child = [True] * (num_cities+1)

for _ in range(num_cities-1):
    u,v = [int(x) for x in input().split()]
    roads[u].append(v)
    roads[v].append(u)
    


todo = [1]
i = 0

while i < len(todo):
    c = todo[i]
    child[c] = False
    for j in roads[c]:
        if child[j]:
            todo.append(j)
    i += 1


combos = [[-1,-1]] * (num_cities+1)

for c in reversed(todo):
    children = [combos[x] for x in roads[c] if combos[x] != [-1,-1]]
    if not children:
        combos[c] = [0,1]
        continue
    slaves = sum(1 for x in children if x[0]==0)
    
    prod = 1
    for cc in children:
        prod = (prod * sum(cc)) % mod
    
    unfree = 1
    
    for cc in children:
        haf = cc[0]
        if 1 & haf:
            haf += mod
        haf = haf >> 1
        unfree = (unfree * haf) % mod
        
    free = (mod + mod +((prod-unfree)*2)) % mod
    
    combos[c] = [free,unfree]
    
    
print(combos[1][0])

