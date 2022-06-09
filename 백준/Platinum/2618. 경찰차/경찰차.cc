#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define all(x) x.begin(), x.end()
ll mod = 998244353;
const ll INF = 1e18;
int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int kdy[8] = {2, 2, 1, 1, -2, -2, -1, -1}, kdx[8] = {1, -1, 2, -2, 1, -1, 2, -2};

int out(int i, int j, int a, int b) {return i > a || i < 1 || j > b || j < 1;}
int out0(int i, int j, int a, int b) {return i >= a || i < 0 || j >= b || j < 0;}

template <class T>
void ct(T&& v){
  cout << forward<T>(v) << '\n';
}

template <class T, class ...Args>
void ct(T&& v, Args&& ...args){
  cout << forward<T>(v) << ' ';
  ct(forward<Args>(args)...);
}

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

pii arr[1010];
int ans[1010];
int dp[1010][1010];
int n, m;

int calc(int a, int b, int c) {
    if (a == 0) {
        if (c == 0) return abs(1 - arr[b].first) + abs(1 - arr[b].second); 
        return abs(n - arr[b].first) + abs(n - arr[b].second); 
    } 
    return abs(arr[a].first - arr[b].first) + abs(arr[a].second - arr[b].second); 
}

int f(int a, int b) {
    int t = max(a, b) + 1;
    if (t > m) return 0;
    int& ret = dp[a][b];
    if (ret != -1) return ret;
    ret = 0;
    
    int l = calc(a, t, 0) + f(t, b);
    int r = calc(b, t, 1) + f(a, t);
    ret = min(l, r);
    return ret;
}

void g(int a, int b) {
    int t = max(a, b) + 1;
    if (t > m) return;
    
    int l = calc(a, t, 0) + f(t, b);
    int r = calc(b, t, 1) + f(a, t);
    if (l < r) {
        ans[t] = 1;
        g(t, b);
    }
    else {
        ans[t] = 2;
        g(a, t);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> arr[i].first >> arr[i].second;
    for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++) dp[i][j] = -1;
    ct(f(0, 0));
    g(0, 0);
    for (int i = 1; i <= m; i++) ct(ans[i]);
}


int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1; 
    while (T--) solve();
} 