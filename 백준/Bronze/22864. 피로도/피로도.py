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

A, B, C, M = MIS()

ans = 0
cnt = 0
for i in range(24):
    if cnt+A > M:
        cnt = max(cnt-C, 0)
    else:
        ans += B
        cnt += A
print(ans)