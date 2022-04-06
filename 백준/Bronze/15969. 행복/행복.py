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

N = int(R())
L = list(MIS())
print(max(L)-min(L))