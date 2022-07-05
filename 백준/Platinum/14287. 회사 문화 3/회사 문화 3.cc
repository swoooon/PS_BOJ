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

int out1(int i, int j, int a, int b) {return i > a || i < 1 || j > b || j < 1;}
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

class SegmentTree {
public:
	vector<ll> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	void upd(int node, int l, int r, int target, ll val) {
		if (target < l || target > r) return;
		if (target == l && target == r) {
            seg[node] += val;
            return;
        }
		int mid = (l + r) / 2;
        upd(node*2, l, mid, target, val);
        upd(node*2+1, mid+1, r, target, val);
		seg[node] = (
			seg[node*2] + 
			seg[node*2+1]
		);
        return;
	}
	ll query(int node, int l, int r, int wl, int wr) {
		if (l > wr || r < wl) return 0;
		if (wl <= l && r <= wr) return seg[node];
		int mid = (l + r) / 2;
		return (
			query(node * 2, l, mid, wl, wr) +
			query(node * 2 + 1, mid + 1, r, wl, wr)
		);
	}
};

int in[101010], out[101010], dfsn;
vector<int> adj[101010];

void dfs(int x) {
	in[x] = ++dfsn;
	for (int i : adj[x]) {
		dfs(i);
	}
	out[x] = dfsn;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		if (i == 1) continue;
		adj[t].push_back(i);
	}
	SegmentTree seg(n);
	dfs(1);
	while (m--) {
		int a, b, c; cin >> a >> b;
		if (a == 1) {
			cin >> c;
			seg.upd(1, 1, n, in[b], c);
		} else {
			ct(seg.query(1, 1, n, in[b], out[b]));
		}
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