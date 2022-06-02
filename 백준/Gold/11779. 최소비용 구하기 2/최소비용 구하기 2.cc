#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;
#define ct(x) cout << x << '\n'
#define ct2(x, y) cout << x << ' ' << y << '\n'
#define ct3(x, y, z) cout << x << ' ' << y << ' ' << z << '\n'
#define ct4(x, y, z, w) cout << x << ' ' << y << ' ' << z << ' ' << w << '\n'
#define all(x) x.begin(), x.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

void debug() {

}

vector<pii> adj[1010];
ll dist[1010];
int pre[1010];

void solve() {
    int n; cin >> n;
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }
    for (int i = 1; i <= n; i++) dist[i] = INF;
    int s, e; cin >> s >> e;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [p, q] = pq.top(); pq.pop();
        if (p > dist[q]) continue;
        dist[q] = p;
        for (auto [cost, next] : adj[q]) {
            if (dist[next] > cost + dist[q]) {
                dist[next] = cost + dist[q];
                pq.push({dist[next], next});
                pre[next] = q;
            }
        }
    }
    ct(dist[e]);
    vector<int> ans;
    for (;e;e = pre[e]) {
        ans.push_back(e);
    }
    ct(ans.size());
    reverse(all(ans));
    for (int i: ans) cout << i << " ";
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    ll T=1;
    while (T--) solve();
} 