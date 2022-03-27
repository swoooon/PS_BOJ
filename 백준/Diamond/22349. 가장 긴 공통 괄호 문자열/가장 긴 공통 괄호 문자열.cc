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

void debug() {

}

struct SegmentTree {
	vector<int> seg;
    vector<int> psum;
	int n;
	SegmentTree(string& s) {
        this->n = s.size();
		seg.resize(4 * n + 5);
        psum.resize(n+1);
        for (int i = 1; i <= n; i++) {
            if (s[i-1] == '(') psum[i] = psum[i-1] + 1;
            else psum[i] = psum[i-1] - 1;
        }
	}
    void upd(int node, int l, int r) {
        if (l == r) {
            seg[node] = psum[l];
            return;
        }
        int mid = (l+r)/2;
        upd(node*2, l, mid); upd(node*2+1, mid+1, r);
        seg[node] = min(seg[node*2], seg[node*2+1]); 
        return;
    }
    int q(int node, int l, int r, int wl, int wr) {
        if (wl > wr) return 100000009;
        if (wl > r || l > wr) return 100000009;
        if (wl <= l && r <= wr) return seg[node];
        int mid = (l+r)/2;
        return min(q(node*2, l, mid, wl, wr), q(node*2+1, mid+1, r, wl, wr));
    }
};

vector<int> getSA(const string& in) {
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


vector<int> getLCP(const string& in, const vector<int>& sa) {
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



void solve() {
    string a, b; cin >> a >> b;
    string c = a+'$'+b;
    auto sa = getSA(c);
    auto lcp = getLCP(c, sa);
    int n = c.size(), al = a.size();
    SegmentTree seg(a);
    seg.upd(1, 0, al);
    int aans = 0;
    for (int i = 0; i < n-1; i++) {
        if ((sa[i] < al) == (sa[i+1] < al)) continue;
        int idx = min(sa[i], sa[i+1]);
        if (idx >= al) continue;
        if (lcp[i] <= aans) continue;
        int l = idx+1, r = idx+lcp[i];
        int ret = seg.q(1, 0, al, l, r);
        if (ret > seg.psum[idx]) {
               continue;
        }
        int temp = -1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (seg.psum[mid] < seg.psum[idx]) {
                r = mid-1;
                temp = mid;
                continue;
            }
            int ret = seg.q(1, 0, al, idx, mid);
            if (ret < seg.psum[idx]) {
                r = mid-1;
                temp = mid;
            }
            else {
                l = mid+1;
            }
        }
        int ans = 0;
        if (temp == -1) {
            l = idx, r = idx+lcp[i];
            while (l <= r) {
                int mid = (l+r)/2;
                int ret = seg.q(1, 0, al, mid, r);
                if (ret <= seg.psum[idx]) {
                    ans = mid-idx;
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
        }
        else {
            ans = temp - idx -1 ;
        }
        aans = max(ans, aans);
    }
    ct(aans);
}



int main() {
    FASTIO
    ll T; cin >> T;
    while (T--) solve();
} 
