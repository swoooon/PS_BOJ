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

const ll mod = 1e9+7;
int dy[4] = {1, 0, -1, 0}, dx[4] = {0, 1, 0, -1};


ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}

const int NMAX = 100010;
int N, Q;
vector<pii> Edges;

struct SegmentTree {
	vector<ll> seg;
	int n;
	SegmentTree() {
		seg.resize(4 * NMAX + 5);
		this->n = NMAX;
	}
	void upd(int node, int l, int r, int target, ll val) {
		if (target < l || target > r) return;
		if (target == l && target == r) {
            seg[node] = val;
            return;
        }
		int mid = (l + r) / 2;
        upd(node*2, l, mid, target, val);
        upd(node*2+1, mid+1, r, target, val);
		seg[node] = max(seg[node*2], seg[node*2+1]);
        return;
	}
	ll query(int node, int l, int r, int wl, int wr) {
		if (l > wr || r < wl) return 0;
		if (wl <= l && r <= wr) return seg[node];
		int mid = (l + r) / 2;
		return max(
			query(node * 2, l, mid, wl, wr),
			query(node * 2 + 1, mid + 1, r, wl, wr)
		);
	}
    void upd(int idx, int val) {
        upd(1, 1, n, idx, val);
    }
    ll query(int wl, int wr) {
        return query(1, 1, n, wl, wr);
    }
} seg;


struct hld {
	vector<int> par, head, heavy, pos, weight, dep;
    vector<pii> adj[NMAX];
	int cur_pos;
	void init() {
		dep = weight = par = head = pos = vector<int>(NMAX);
		heavy = vector<int>(NMAX, -1);
		cur_pos = 1;
		dfs(1);
		decompose(1, 0);
		for (int i = 1; i <= N; i++)
            seg.upd(pos[i], weight[i]);
	}
	int dfs(int cur) {
		int ret = 1, mxc = 0;
		for (pii it : adj[cur]) {
			int next = it.first, w = it.second;
			if (next == par[cur]) continue;
			weight[next] = w, par[next] = cur, dep[next] = dep[cur] + 1;
			int csz = dfs(next);
			ret += csz;
			if (csz > mxc)
				mxc = csz, heavy[cur] = next;
		}
		return ret;
	}
	void decompose(int cur, int h) {
		head[cur] = h, pos[cur] = cur_pos++;
		if (heavy[cur] != -1) decompose(heavy[cur], h);
		for (pii it : adj[cur]) {
			int next = it.first;
			if (next != par[cur] && next != heavy[cur])
				decompose(next, next);
		}
	}
	int query(int a, int b) {
		int ret = 0;
		for (; head[a] != head[b]; b = par[head[b]]) {
			if (dep[head[a]] > dep[head[b]]) swap(a, b);
			int tmp = seg.query(pos[head[b]], pos[b]);
			ret = max(ret, tmp);
		}
		if (dep[a] > dep[b]) swap(a, b);
		if (pos[a] != pos[b]) {
			int tmp = seg.query(pos[a] + 1, pos[b]);
			ret = max(ret, tmp);
		}

		return ret;
	}
	void update(int i, int val) {
		seg.upd(pos[i], val);
	}
} hld;


void solve() {
    cin >> N;
    Edges.resize(N);
    for (int i = 1; i <= N-1; i++) {
        int a, b, c; cin >> a >> b >> c;
        hld.adj[a].push_back({b, c});
        hld.adj[b].push_back({a, c});
        Edges[i] = {a, b};
    }
    hld.init();
    cin >> Q;
    while (Q--) {
        int a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            if (hld.par[Edges[b].first] == Edges[b].second) hld.update(Edges[b].first, c);
            else hld.update(Edges[b].second, c);
        }
        else ct(hld.query(b, c));
    }
    
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    ll T=1;
    while (T--) solve();
} 