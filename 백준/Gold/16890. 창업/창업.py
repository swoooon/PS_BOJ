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

S = list(R())
T = list(R())
l = len(S)
S.sort()
T.sort(reverse=1)
S = S[:(len(S)+1)//2]
T = T[:len(T)//2]
SL = collections.deque()
TL = collections.deque()
for i in S:
    SL.append(i)
for i in T:
    TL.append(i)
t = 0
ans = []
ans2 = []
for i in range(l):
    if t == 0:
        if not TL or SL[0] < TL[0]: ans.append(SL.popleft())
        else: ans2.append(SL.pop())
    else:
        if not SL or SL[0] < TL[0]: ans.append(TL.popleft())
        else: ans2.append(TL.pop())
    t ^= 1
print("".join(ans+ans2[::-1]))
