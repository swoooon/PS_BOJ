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
const ll mod = 1000000000;
const ll INF = 1000000000;
int dy[4] = {1, 0, -1, 0}, dx[8] = {0, 1, 0, -1};
int kdy[8] = {2, 2, 1, 1, -2, -2, -1, -1}, kdx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
#define all(x) x.begin(), x.end()

int out(int i, int j, int a, int b) {return i > a || i < 1 || j > b || j < 1;}

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

int dp[3030][3030];

void solve() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++) cin >> dp[i][j];
	int flag = 1;
	int step = 1, remain = k-1;
	while (remain) {
		remain -= step;
		for (int i = 1; i <= n-step; i++) {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = max(max(dp[i][j], dp[i+step][j]), dp[i+step][j+step]);
			}
		}
		if (flag) {flag=0; continue;}
		if (step == 1) step = 2;
		else step = step*3/2;
		if (step > remain) step = remain;
	}
	ll ans = 0;
	for (int i = 1; i <= n-k+1; i++) {
		for (int j = 1; j <= i+1; j++) ans += dp[i][j];
	}
	ct(ans);
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1;
    while(T--) solve();
} 