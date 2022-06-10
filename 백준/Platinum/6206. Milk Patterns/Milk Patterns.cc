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


vector<int> getSA(const vector<int>& in) {
	int n = (int)in.size(), c = 0;
	vector<int> temp(n), pos2bckt(n), bckt(n), bpos(n), out(n);
	for (int i = 0; i < n; i++) out[i] = i;
		sort(out.begin(), out.end(), [&](int a, int b) { return in[a] < in[b]; });
	for (int i = 0; i < n; i++) {
		bckt[i] = c;
		if (i + 1 == n || in[out[i]] != in[out[i + 1]]) c++;
	}
	for (int h = 1; h < n && c < n; h <<= 1) {
	for (int i = 0; i < n; i++) pos2bckt[out[i]] = bckt[i];
	for (int i = n - 1; i >= 0; i--) bpos[bckt[i]] = i;
	for (int i = 0; i < n; i++)
		if (out[i] >= n - h) temp[bpos[bckt[i]]++] = out[i];
	for (int i = 0; i < n; i++)
		if (out[i] >= h) temp[bpos[pos2bckt[out[i] - h]]++] = out[i] - h;
	c = 0;
	for (int i = 0; i + 1 < n; i++) {
		int a = (bckt[i] != bckt[i + 1]) || (temp[i] >= n - h)
				|| (pos2bckt[temp[i + 1] + h] != pos2bckt[temp[i] + h]);
		bckt[i] = c;
		c += a;
		}
		bckt[n - 1] = c++;
		temp.swap(out);
	}
	return out;
}


vector<int> getLCP(const vector<int>& in, const vector<int>& sa) {
	int n = (int)in.size();
	if (n == 0) return vector<int>();
	vector<int> rank(n), height(n - 1);
	for (int i = 0; i < n; i++) rank[sa[i]] = i;
	for (int i = 0, h = 0; i < n; i++) {
		if (rank[i] == 0) continue;
		int j = sa[rank[i] - 1];
		while (i + h < n && j + h < n && in[i + h] == in[j + h]) h++;
		height[rank[i] - 1] = h;
		if (h > 0) h--;
	}
	return height;
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
            seg[node] = val;
            return;
        }
		int mid = (l + r) / 2;
        upd(node*2, l, mid, target, val);
        upd(node*2+1, mid+1, r, target, val);
		seg[node] = min(
			seg[node*2],
			seg[node*2+1]
		);
        return;
	}
	ll query(int node, int l, int r, int wl, int wr) {
		if (l > wr || r < wl) return 1e9;
		if (wl <= l && r <= wr) return seg[node];
		int mid = (l + r) / 2;
		return min(
			query(node * 2, l, mid, wl, wr),
			query(node * 2 + 1, mid + 1, r, wl, wr)
		);
	}
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        arr.push_back(t);
    }
    auto sa = getSA(arr);
    auto lcp = getLCP(arr, sa);
    SegmentTree seg(n);
    for (int i = 0; i < n-1; i++) {
        seg.upd(1, 0, n-2, i, lcp[i]);
    }
    ll ans = 0;
    for (int i = 0; i+k-2 <= n-2; i++) {
        ans = max(ans, seg.query(1, 0, n-2, i, i+k-2));
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