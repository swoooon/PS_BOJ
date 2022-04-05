import sys
import math
import collections
import bisect
import itertools

dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
dy8 = [1, 0, -1, 0, 1, 1, -1, -1]
dx8 = [0, 1, 0, -1, -1, 1, 1, -1]
R = lambda : sys.stdin.readline().rstrip()
MIS = lambda : map(int, R().split())
mod = 1000000007

N, M = MIS()
L = list(MIS())
L.sort(reverse=1)
cnt = 0
ans = 0
for i in L:
    ans += max(0, i-cnt)
    cnt += 1
print(ans)