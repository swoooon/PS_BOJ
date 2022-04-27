N = int(input())
L = list(map(int, input().split()))
fibo = [0, 1]
idx = 2
while 1:
    a = fibo[idx-1] + fibo[idx-2]
    fibo.append(fibo[idx-1] + fibo[idx-2])
    if fibo[idx] > 3*1000000: break
    idx += 1

G = [0]*(3000001)

for i in range(1, 3000001):
    check = [0]*(17)
    idx = 2
    while i - fibo[idx] >= 0:
        check[G[i-fibo[idx]]] = 1
        idx += 1

    idx = 0
    while check[idx]: idx += 1
    G[i] = idx

ans = 0
for i in L:
    ans ^= G[i]
print("koosaga" if ans else "cubelover")
