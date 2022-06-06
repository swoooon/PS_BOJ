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
#define all(x) x.begin(), x.end()
ll mod = 998244353;
const ll INF = 1e18;
int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int kdy[8] = {2, 2, 1, 1, -2, -2, -1, -1}, kdx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
#define all(x) x.begin(), x.end()

int out(int i, int j, int a, int b) {return i > a || i < 1 || j > b || j < 1;}
int out0(int i, int j, int a, int b) {return i >= a || i < 0 || j >= b || j < 0;}

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

int arr[11][11];
int tmp[11][11];

void f(int i, int j) {
    tmp[i][j] ^= 1;
    for (int d = 0; d < 4; d++) {
        int ri = i+dy[d], rj = j+dx[d];
        if (out0(ri, rj, 10, 10)) continue;
        tmp[ri][rj] ^= 1;
    }
}

void solve() {
    ll ans = INF;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char t; cin >> t;
            arr[i][j] = t == 'O';
        }
    }

    for (int bit = 0; bit < (1 << 10); bit++) {
        ll cnt = 0;
        for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) tmp[i][j] = arr[i][j];
        for (int j = 0; j < 10; j++) {
            if ((1<<j) & bit) {
                f(0, j);
                cnt++;
            }
        }
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (tmp[i-1][j]) {
                    f(i, j);
                    cnt++;
                }
            }
        }
        int can = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) can += tmp[i][j];
        }
        if (can) continue;
        ans = min(ans, cnt);
    }
    if (ans != INF) ct(ans);
    else ct(-1);
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1; 
    while (T--) solve();
} 