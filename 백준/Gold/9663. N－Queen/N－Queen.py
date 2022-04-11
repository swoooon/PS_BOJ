n, s = int(input()), 0
x , plusdia, minusdia = [0]*n, [0]*(2*n-1), [0]*(2*n-1)

def BT(i):
    global s
    if i == n:
        s += 1
        return
    for j in range(n):
        if not (x[j] or plusdia[i+j] or minusdia[i-j+n-1]):
            x[j] = plusdia[i+j] = minusdia[i-j+n-1] = 1
            BT(i+1)
            x[j] = plusdia[i+j] = minusdia[i-j+n-1] = 0

BT(0)
print(s)