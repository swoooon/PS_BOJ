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
const ll mod = 998244353;
const ll INF = 1000000007;
int dy[4] = {1, 0, -1, 0}, dx[8] = {0, 1, 0, -1};
int kdy[8] = {2, 2, 1, 1, -2, -2, -1, -1}, kdx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
#define all(x) x.begin(), x.end()

int out(int i, int j, int a, int b) {return i > a || i < 1 || j > b || j < 1;}

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

int dp[1010][1010];

int f(int n, int k) {
    if (k == 0 || n == k) return 1;
    int& ret = dp[n][k];
    if (ret != -1) return ret;
    return ret = (f(n-1, k-1) + f(n-1, k)) % 10007;
}

void solve() {
    int n, k; cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    ct(f(n, k));
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1;
    while(T--) solve();
} 