#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b) return gcd(b, a%b);
    return a;
}

ll ceil(ll a, ll b) {
    return (a-1)/b + 1;
}
vector<int> v;
vector<int> idx;
vector<int> num;
vector<int> pre;
vector<int>::iterator iter;

void debug() {

}


void solve() {
    int N; cin >> N;
    pre.resize(N);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        num.push_back(a);
        if (i == 0) {
            v.push_back(a);
            pre[i] = -1;
            idx.push_back(i);
        }
        if (v.back() < a) {
            v.push_back(a);
            pre[i] = idx.back();
            idx.push_back(i);
        }
        else {
            iter = lower_bound(v.begin(), v.end(), a);
            *iter = a;
            int now = iter - v.begin();
            if (now > 0) pre[i] = idx[now-1];
            else pre[i] = -1;
            idx[now] = i;
        }
    }
    cout << v.size() << '\n';

    int b = idx.back();
    vector<int> ans;
    while (b != -1) {
        ans.push_back(num[b]);
        b = pre[b];
    }
    sort(ans.begin(), ans.end());
    for (auto c : ans) cout << c << ' ';
}




int main() {
    FASTIO
    int T=1;
    while (T--) solve();
} 