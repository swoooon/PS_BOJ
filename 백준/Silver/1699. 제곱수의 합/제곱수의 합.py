import sys

r = sys.stdin.readline
N = int(r())
L = [0 for _ in range(N+1)]

for i in range(1,N+1):
    L[i] = i

for i in range(1,N+1):
    for j in range(1,int(N**0.5)+1):
        if L[i] > L[i-j*j] + 1:
            L[i] = L[i-j*j] + 1

print(L[N])