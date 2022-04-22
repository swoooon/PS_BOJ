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

print(["CY","SK"][[0, 1, 0, 1, 1, 1, 1][int(R())%7]])