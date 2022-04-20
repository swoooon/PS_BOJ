import sys
import math
import collections
import bisect
import itertools
import random

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
dy8 = [1, 0, -1, 0, 1, 1, -1, -1]
dx8 = [0, 1, 0, -1, -1, 1, 1, -1]
R = lambda : sys.stdin.readline().rstrip()
MIS = lambda : map(int, R().split())
mod = 1000000007

N = int(R())
L = list(MIS())
T = []

for i in range(N):
    for j in range(i+1, N):
        T.append((L[i]+L[j], i, j))
ans = 4594394594943945345959935953959359
T.sort()
tl = len(T)
for i in range(tl-1):
    s, a, b = T[i]
    k, c, d = T[i+1]
    if a == c or a == d or b == c or b == d: continue
    ans = min(ans, k-s)
print(ans)