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


void solve() {
    int n; cin >> n;
    for(;n--;) {
        int a, b; cin >> a >> b;
        ct(a+b);
    }
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1; 
    while (T--) solve();
} 