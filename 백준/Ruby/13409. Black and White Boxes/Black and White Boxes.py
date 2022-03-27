from itertools import *
tt = pow(2, 40)
N = int(input())
L = []
for i in range(N):
    a = input()
    t = tt+0
    temp = 0
    flag = 0
    for j in range(len(a)):
        if flag or (j != 0 and a[j] != a[j-1]):
            t //= 2
            flag = 1
        if a[j] == "W": temp += t
        else: temp -= t
    L.append((temp, len(a)))
L1 = L[:N//2]
L2 = L[N//2:]
dic = {}
ans = 0
for i in range(len(L1)+1):
    for j in combinations(L1, i):
        a, b = 0, 0
        for k, l in j:
            a += k
            b += l
        if a in dic:
            if dic[a] < b: dic[a] = b
        else: dic[a] = b
for i in range(len(L2)+1):
    for j in combinations(L2, i):
        a, b = 0, 0
        for k, l in j:
            a += k
            b += l
        if -a in dic: ans = max(ans, dic[-a] + b)
print(ans)
