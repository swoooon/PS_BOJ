import sys
import math
import collections
import bisect

INF = sys.maxsize*3000
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
dy8 = [1, 0, -1, 0, 1, 1, -1, -1]
dx8 = [0, 1, 0, -1, -1, 1, 1, -1]
R = lambda : sys.stdin.readline().rstrip()
MIS = lambda : map(int, R().split())
mod = 1000000007

N, M, V, A, B = R().split()
N = int(N)
M = int(M)
V = float(V)
A = int(A)
B = int(B)
adj = []
for i in range(M):
    a, b, c = R().split()
    a = int(a)
    b = int(b)
    c = float(c)
    adj.append((a, b, c))

dist = [INF]*(N+1)
dist[A] = V
flag = 1
for i in range(1, N+1):
    for j in range(M):
        a, b, c = adj[j][0], adj[j][1], adj[j][2]
        if dist[a] != INF and dist[b] > dist[a]*c:
            dist[b] = dist[a]*c
            if i == N:
                flag = 0

if flag or dist[B] == INF: print(dist[B])
else: print(0)
