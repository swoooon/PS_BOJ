#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;

int arr[101010];
int temp[101000];


void mg(int l, int mid, int r) {
    int i = l, j = mid+1, k = l;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    for (int x = l; x <= r; x++) arr[x] = temp[x];
}

void mgSort(int l, int r) {
    if (l >= r) return;
    int mid = l+r>>1;
    mgSort(l, mid); mgSort(mid+1, r);
    mg(l, mid, r);
}

int b_search(int n, int target) {
    int l = 0, r = n-1;
    while (l <= r) {
        int mid = l+r>>1;
        if (arr[mid] == target) return 1;
        if (arr[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return 0;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    mgSort(0, n-1);
    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        cout << b_search(n, t) << '\n';
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