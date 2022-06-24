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
const ll NMAX = 101010;
const ll mod = 1e9+7;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};
#define all(x) x.begin(), x.end()


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

class LazySegmentTree {
public:
	vector<ll> seg;
    vector<ll> lazy;
	int n;
	LazySegmentTree(int n) {
		seg.resize(4 * n + 9);
        lazy.resize(4 * n + 9);
		this->n = n;
	}
    void prop(int node, int l, int r) {
        if (lazy[node] == 0) return;
        seg[node] += (r - l+1)*lazy[node]; //
        if (l != r) {
            lazy[node*2] += lazy[node]; //
            lazy[node*2+1] += lazy[node]; //
        }
        lazy[node] = 0;
    }


	void upd(int node, int l, int r, int wl, int wr, ll val) {
        prop(node, l, r);
		if (wr < l || wl > r) return;
		if (wl <= l && r <= wr) {
            lazy[node] += val;
            prop(node, l, r);
            return;
        }

		int mid = (l + r) / 2;
        upd(node * 2, l, mid, wl, wr, val);
        upd(node * 2 + 1, mid + 1, r, wl, wr, val);
		seg[node] = (
            seg[node*2] + //
            seg[node*2+1]
        );
	}
    
	ll query(int node, int l, int r, int wl, int wr) {
        prop(node, l, r);
		if (l > wr || r < wl) return 0;
		if (wl <= l && r <= wr) return seg[node];
		int mid = (l + r) / 2;
		return (
			query(node * 2, l, mid, wl, wr) + //
			query(node * 2 + 1, mid + 1, r, wl, wr)
			);
	}
};

int arr[101010];

void solve() {
    int N; cin >> N;
    LazySegmentTree seg(N);
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) 
        seg.upd(1, 1, N, i, i, arr[i]-arr[i-1]);
    int Q; cin >> Q;
    while (Q--) {
        int a; cin >> a;
        if (a == 1) {
            int b, c; cin >> b >> c;
            seg.upd(1, 1, N, b, c, 1);
            seg.upd(1, 1, N, c+1, c+1, -(c-b+1));
        }
        else {
            int b; cin >> b;
            ct(seg.query(1, 1, N, 1, b));
        }
    }
    
}



int main() {
    FASTIO
    ll T=1;
    while (T--) solve();
} 