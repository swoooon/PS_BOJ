import sys
import collections
import itertools
import heapq
import decimal
import math

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
R = lambda : sys.stdin.readline().rstrip()
MIS = lambda : map(int, R().split())
mod = 1000000007

N = int(R())
NN = int(N**0.5+2)
t = 9459439595499549995359954939
ans = [1, 1, 1]
for i in range(1, NN):
    for j in range(1, NN):
        if N%(i*j):continue
        s = N//(i*j)
        if i*j+j*s+s*i < t:
            ans = [i, j, s]
            t = i*j+j*s+s*i
print(*ans)