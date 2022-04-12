import sys
import collections

R = lambda : sys.stdin.readline().rstrip()
MIS = lambda : map(int, R().split())

def f(s, e):
    if s == e: return 0
    if dp[s][e] != -1: return dp[s][e]
    if e-s == 1:
        dp[s][e] = L[s][0]*L[s][1]*L[e][1]
        return dp[s][e]
    ret = 9876543210
    for i in range(s, e):
        ret = min(ret, f(s, i) + f(i+1, e) + L[s][0]*L[i][1]*L[e][1])
    dp[s][e] = ret
    return ret


N = int(R())
L = [list(MIS()) for _ in range(N)]
dp = [[-1]*N for _ in range(N)]

print(f(0, N-1))