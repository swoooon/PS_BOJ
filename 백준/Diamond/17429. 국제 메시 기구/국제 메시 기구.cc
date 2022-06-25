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

const int NMAX = 500100;

//////////////////////////////////////

struct HeavyLightDecomposition {

    struct LazySegmentTree {
        vector<unsigned int> seg;
        vector<unsigned int> lazy;
        vector<unsigned int> lazy2;
        int n;
        LazySegmentTree() {
            this->n = NMAX;
            seg.resize(4 * n + 9);
            lazy.resize(4 * n + 9);
            lazy2.resize(4 * n + 9, 1);
        }
        void prop(int node, int l, int r) {
            if (lazy[node] == 0 && lazy2[node] == 1) return;
            seg[node] *= lazy2[node];
            seg[node] += (r - l+1)*lazy[node]; //
            if (l != r) {
                lazy2[node*2] *= lazy2[node];
                lazy[node*2] *= lazy2[node]; //
                lazy[node*2] += lazy[node];
                lazy2[node*2+1] *= lazy2[node];
                lazy[node*2+1] *= lazy2[node]; //
                lazy[node*2+1] += lazy[node];
            }
            lazy[node] = 0, lazy2[node] = 1;
        }


        void upd(int node, int l, int r, int wl, int wr, unsigned int val, int t) {
            prop(node, l, r);
            if (wr < l || wl > r) return;
            if (wl <= l && r <= wr) {
                if (t == 1) lazy[node] += val;
                else lazy2[node] *= val;
                prop(node, l, r);
                return;
            }

            int mid = (l + r) / 2;
            upd(node * 2, l, mid, wl, wr, val, t);
            upd(node * 2 + 1, mid + 1, r, wl, wr, val, t);
            seg[node] = (
                seg[node*2] + //
                seg[node*2+1]
            );
        }
        
        unsigned int query(int node, int l, int r, int wl, int wr) {
            prop(node, l, r);
            if (l > wr || r < wl) return 0;
            if (wl <= l && r <= wr) return seg[node];
            int mid = (l + r) / 2;
            return (
                query(node * 2, l, mid, wl, wr) + //
                query(node * 2 + 1, mid + 1, r, wl, wr)
                );
        }
        unsigned int query(int wl, int wr) {
            return query(1, 1, n, wl, wr);
        }
        void upd(int wl, int wr, int val, int t) {
            upd(1, 1, n, wl, wr, val, t);
        }
    };
	LazySegmentTree seg;
	vector<int> par, head, heavy, pos, weight, dep, rev, out;
    vector<pii> adj[NMAX];
	int cur_pos;
	void init() {
		dep = weight = par = head = pos = rev = out = vector<int>(NMAX);
		heavy = vector<int>(NMAX, -1);
		cur_pos = 0;
		dfs(1);
		decompose(1, 0);
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
        ++cur_pos;
		head[cur] = h, rev[cur_pos] = cur, pos[cur] = cur_pos;
		if (heavy[cur] != -1) decompose(heavy[cur], h);
		for (pii it : adj[cur]) {
			int next = it.first;
			if (next != par[cur] && next != heavy[cur])
				decompose(next, next);
		}
        out[cur] = cur_pos;
	}


    void query1(int a, int val) {
        seg.upd(pos[a], out[a], val, 1);
    }

	void query2(int a, int b, int val) {
		for (; head[a] != head[b]; b = par[head[b]]) {         // 서로 다른 체인에 존재하는 상황
			if (dep[head[a]] > dep[head[b]]) swap(a, b); 
			seg.upd(pos[head[b]], pos[b], val, 1);                       ///////////////////insert///////////////////
		}
		if (dep[a] > dep[b]) swap(a, b);
        seg.upd(pos[a], pos[b], val, 1);                         ///////////////////insert///////////////////
	}


    void query3(int a, int val) {
        seg.upd(pos[a], out[a], val, 0);
    }

	void query4(int a, int b, int val) {
		for (; head[a] != head[b]; b = par[head[b]]) {         // 서로 다른 체인에 존재하는 상황
			if (dep[head[a]] > dep[head[b]]) swap(a, b); 
			seg.upd(pos[head[b]], pos[b], val, 0);                       ///////////////////insert///////////////////
		}
		if (dep[a] > dep[b]) swap(a, b);
        seg.upd(pos[a], pos[b], val, 0);                         ///////////////////insert///////////////////
	}

    unsigned int query5(int a) {
        return seg.query(pos[a], out[a]);
    }

	unsigned int query6(int a, int b) {
		unsigned int ret = 0;
		for (; head[a] != head[b]; b = par[head[b]]) {         // 서로 다른 체인에 존재하는 상황
			if (dep[head[a]] > dep[head[b]]) swap(a, b); 
			unsigned int tmp = seg.query(pos[head[b]], pos[b]);
			ret += tmp;                           ///////////////////insert///////////////////
		}
		if (dep[a] > dep[b]) swap(a, b);
        unsigned int tmp = seg.query(pos[a], pos[b]); 
        ret += tmp;                              ///////////////////insert///////////////////
		return ret;
	}

};

int arr[NMAX];

void solve() {
    int N, Q; cin >> N >> Q;
    HeavyLightDecomposition hld;
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        hld.adj[a].push_back({b, 0});
        hld.adj[b].push_back({a, 0});
    }
    hld.init();
    while (Q--) {
        int a, u, v, c; cin >> a;
        if (a == 1) {
            cin >> u >> c;
            hld.query1(u, c);
        }
        else if (a == 2) {
            cin >> u >> v >> c;
            hld.query2(u, v, c);
        }
        else if (a == 3) {
            cin >> u >> c;
            hld.query3(u, c);
        }
        else if (a == 4) {
            cin >> u >> v >> c;
            hld.query4(u, v, c);
        }
        else if (a == 5) {
            cin >> u;
            ct(hld.query5(u));
        }
        else {
            cin >> u >> v;
            ct(hld.query6(u, v));
        }
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