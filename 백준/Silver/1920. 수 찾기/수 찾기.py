def binarysearch(start, end, target):
    while start <= end:
        mid = (start + end)//2
        if target == NL[mid]:
            return 1

        elif target > NL[mid]:
            start = mid + 1

        else:
            end = mid - 1
    return 0


N = int(input())
NL = sorted(list(map(int, input().split())))
length = len(NL)
M = int(input())
ML = list(map(int, input().split()))

for i in ML:
    print(binarysearch(0, length - 1, i))