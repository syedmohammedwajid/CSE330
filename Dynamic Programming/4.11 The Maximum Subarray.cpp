#!/bin/python3

test = int(input())
while test:
    test -= 1
    input()
    num_list = [int(x) for x in input().split()]
    max_sum = 0
    tmp_sum = 0
    max_non_contg = 0
    flg = False
    mx = max(num_list)
    if mx < 0:
        print(str(mx) + " " + str(mx))
        continue
    for i in range(len(num_list)):
        if tmp_sum < 0:
            tmp_sum = 0
        tmp_sum += num_list[i]
        if tmp_sum > max_sum:
            max_sum = tmp_sum
        if num_list[i] > 0:
            max_non_contg += num_list[i]
    print(str(max_sum) + " " + str(max_non_contg))
