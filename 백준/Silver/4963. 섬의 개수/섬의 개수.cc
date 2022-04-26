#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define ct(x) cout << x << '\n'
#define ct2(x, y) cout << x << ' ' << y << '\n'
#define ct3(x, y, z) cout << x << ' ' << y << ' ' << z << '\n'
#define ct4(x, y, z, w) cout << x << ' ' << y << ' ' << z << ' ' << w << '\n'
ll mod = 998244353;
const ll INF = 1e18;
int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int kdy[8] = {2, 2, 1, 1, -2, -2, -1, -1}, kdx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
#define all(x) x.begin(), x.end()

int out(int i, int j, int a, int b) {return i > a || i < 1 || j > b || j < 1;}

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}


int arr[55][55];
int vis[55][55];
int n, m;

void solve() {
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            vis[i][j] = 0;
        }
    }
    queue<pii> que;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) continue;
            if (arr[i][j]==0) continue;
            que.push({i, j});
            vis[i][j] = 1;
            ans++;
            while (!que.empty()) {
                auto [y, x] = que.front(); que.pop();
                for (int d = 0; d < 8; d++) {
                    int ry = y+dy[d], rx = x+dx[d];
                    if (out(ry+1, rx+1, n, m)) continue;
                    if (vis[ry][rx]) continue;
                    if (arr[ry][rx] == 0) continue;
                    que.push({ry, rx});

                    vis[ry][rx] = 1;
                }
            }
        }
    }
    ct(ans);
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    while (1){
        cin >> m >> n;
        if (n == 0) return 0;
        solve();
    } 
} 