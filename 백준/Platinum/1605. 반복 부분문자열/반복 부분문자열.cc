#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define ct(x) cout << x << '\n'
#define ct2(x, y) cout << x << ' ' << y << '\n'
#define ct3(x, y, z) cout << x << ' ' << y << ' ' << z << '\n'
#define ct4(x, y, z, w) cout << x << ' ' << y << ' ' << z << ' ' << w << '\n'
const ll mod = 1000000000;
const ll INF = 1000000000;
int dy[4] = {1, 0, -1, 0}, dx[8] = {0, 1, 0, -1};
int kdy[8] = {2, 2, 1, 1, -2, -2, -1, -1}, kdx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
#define all(x) x.begin(), x.end()

int out(int i, int j, int a, int b) {return i > a || i < 1 || j > b || j < 1;}

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

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
	int n; cin >> n;
	string s; cin >> s;
	auto sa = getSA(s);
	auto lcp = getLCP(s, sa);
	ct(*max_element(lcp.begin(), lcp.end()));
}



int main() {
    FASTIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int T=1;
    while(T--) solve();
} 