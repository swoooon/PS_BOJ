import sys

r = sys.stdin.readline

N = int(r())
a = 2 
if N % 6 == 2:
    c = N - 4 
    while c > 0: 
        print(a) 
        a += 2 
        if a > N: 
            print(3) 
            print(1) 
            a = 7 
        c -= 1
    print(a) 
    print(5) 
elif N % 6 == 3: 
    a = 4 
    c = N - 3 
    while c > 0: 
        print(a) 
        a += 2 
        if a > N and a % 2 == 0: 
            print(2) 
            a = 5 
        c -= 1 
    print(1) 
    print(3) 
else:
    for i in range(1, N+1): 
        print(a) 
        a += 2 
        if a > N: 
            a = 1