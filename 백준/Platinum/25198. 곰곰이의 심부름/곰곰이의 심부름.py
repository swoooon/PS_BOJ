import sys
import heapq

r = sys.stdin.readline

def dijkstra(dis, S):
    pq = []
    dis[S] = 0
    heapq.heappush(pq, (0, S))
    while pq:
        d, u = heapq.heappop(pq)
        if d > dis[u]: continue
        for v, c in adj[u]:
            if dis[v] > d + c:
                dis[v] = d + c
                heapq.heappush(pq, (dis[v], v))


n = int(r())
S, C, H = map(int, r().split())
adj = [[] for _ in range(n+1)]
for i in range(n-1):
    a, b = map(int, r().split())
    adj[a].append((b, 1))
    adj[b].append((a, 1))

dis1 = [10**18]*(n+1)
disv1 = [10**18]*(n+1)
dijkstra(dis1, S)
dijkstra(disv1, C)
a = dis1[H]
b = disv1[S] + disv1[H]
c = (b-a)//2
ans = (a+1+c)*(a+c)//2 + (c+1)*c//2
print(ans)