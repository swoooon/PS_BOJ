import sys
import collections
import itertools
import heapq

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]

R = lambda: sys.stdin.readline().rstrip()
MIS = lambda: map(int, R().split())
mod = 1000000007

dic = {}
for i in R():
    if i in dic: dic[i] += 1
    else: dic[i] = 1

for i in range(97, 97+26):
    if chr(i) in dic: print(dic[chr(i)])
    else: print(0)
