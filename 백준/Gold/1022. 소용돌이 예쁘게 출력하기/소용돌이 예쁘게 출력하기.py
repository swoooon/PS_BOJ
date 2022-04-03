import sys
import collections
import bisect

INF = sys.maxsize
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
dy8 = [1, 0, -1, 0, 1, 1, -1, -1]
dx8 = [0, 1, 0, -1, -1, 1, 1, -1]
R = lambda : sys.stdin.readline().rstrip()
MIS = lambda : map(int, R().split())
mod = 1000000007

def f(x, y):
    if x == 0 and y == 0: return 1
    k = max(abs(x), abs(y))
    a = (2*k-1)*(2*k-1)
    nx, ny = k, k
    for i in range(2*k):
        ny -= 1
        a += 1
        if y == ny and x == nx:
            return a
    for i in range(2*k):
        a += 1
        nx -= 1
        if y == ny and x == nx:
            return a
    for i in range(2*k):
        a += 1
        ny += 1
        if y == ny and x == nx:
            return a
    for i in range(2*k):
        a += 1
        nx += 1
        if y == ny and x == nx:
            return a

ans = []
l = 0
r1, c1, r2, c2 = MIS()
for i in range(r1, r2+1):
    t = []
    for j in range(c1, c2+1):
        a = f(j, i)
        l = max(l, len(str(a)))
        t.append(f(j, i))
    ans.append(t)

for i in ans:
    for j in i:
        print(f"{str(j).rjust(l, ' ')}", end=" ")
    print()
