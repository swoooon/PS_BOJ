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

S = R()
dic = {}
dic["A"] = 0
dic["B"] = 0
dic["C"] = 0
for i in S:
    dic[i] += 1

ans = []
flag = 1
t = max(0, dic["B"]-dic["C"])
while t and dic["A"] and dic["C"]:
    dic["B"] -= 2
    t -= 1
    dic["A"] -= 1
    dic["C"] -= 1
    ans.append("BCBA")

while dic["A"] and dic["B"] and dic["C"]:
    dic["A"] -= 1
    dic["B"] -= 1
    dic["C"] -= 1
    ans.append("CBA")

if dic["A"] == 0:
    if dic["B"] == 0:
        if dic["C"] <= 1:
            ans.append("C"*dic["C"])
        else: flag = 0
    elif dic["B"] == 1:
        if dic["C"] <= 1:
            ans.append("B"+"C"*dic["C"])
        else: flag = 0
    elif dic["B"] == 2 and dic["C"] == 1:
        ans.append("BCB")
    else: flag = 0
else:
    if dic["B"]:
        if dic["B"] > dic["A"]+1:
            flag = 0
        else:
            ans.append("BA"*(dic["B"]-1)+"B"+(dic["A"]-dic["B"]+1)*"A")
            dic["A"] = 0

    elif dic["C"]:
        if (dic["C"]-1)*2 > dic["A"]:
            flag = 0
        else:
            ans.append("CAA"*(dic["C"]-1)+"C"+(dic["A"]-2*(dic["C"]-1))*"A")
            dic["A"] = 0

if dic["A"]:
    ans.append("A"*dic["A"])

if flag: print("".join(ans))
else: print(-1)

