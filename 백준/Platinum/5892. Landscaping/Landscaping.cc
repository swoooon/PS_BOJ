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

int n, X, Y, Z, A[1010], B[1010], na, nb;
ll dp[1010][1010];

void solve() {
    cin >> n >> X >> Y >> Z;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        for (int j = 0; j < a; j++) A[na++] = i;
        for (int j = 0; j < b; j++) B[nb++] = i;
    } 

    for (int i = 0; i <= na; i++) dp[i][0] = i*Y;
    for (int j = 0; j <= nb; j++) dp[0][j] = j*X;

    for (int i = 1; i <= na; i++) {
        for (int j = 1; j <= nb; j++) {
            dp[i][j] = min(INF, dp[i-1][j]+Y);
            dp[i][j] = min(dp[i][j], dp[i][j-1]+X);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + Z*abs(A[i]-B[j]));
        } 
    }
    ct(dp[na][nb]);

}


int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1;
    while (T--) solve();
} 