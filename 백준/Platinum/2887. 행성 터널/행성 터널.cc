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





struct Node {
    int x, y, z, idx;
};

struct Edge {
    int s, e, c;
};

Node arr[101010];

int uf[101010];

int find(int a) {
    if (a == uf[a]) return a;
    return uf[a] = find(uf[a]);
}

int merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return 0;
    uf[a] = b; return 1;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[i] = {a, b, c, i};
        uf[i] = i;
    }
    vector<Edge> ed;
    sort(arr, arr+n, [&](Node a, Node b){
        return a.x < b.x;
    });
    for (int i = 0; i < n-1; i++) {
        ed.push_back({
            arr[i].idx,
            arr[i+1].idx,
            arr[i+1].x - arr[i].x,
        });
    }
    sort(arr, arr+n, [&](Node a, Node b){
        return a.y < b.y;
    });
    for (int i = 0; i < n-1; i++) {
        ed.push_back({
            arr[i].idx,
            arr[i+1].idx,
            arr[i+1].y - arr[i].y,
        });
    }
    sort(arr, arr+n, [&](Node a, Node b){
        return a.z < b.z;
    });
    for (int i = 0; i < n-1; i++) {
        ed.push_back({
            arr[i].idx,
            arr[i+1].idx,
            arr[i+1].z - arr[i].z,
        });
    }

    sort(all(ed), [&](Edge a, Edge b){
        return a.c < b.c;
    });
    ll ans = 0;
    for (auto [s, e, c] : ed) {
        if (merge(s, e)) ans += c;
    }
    ct(ans);
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1; 
    while (T--) solve();
} 