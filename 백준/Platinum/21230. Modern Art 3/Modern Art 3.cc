#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int N, arr[303], dp[303][303];

int find(int start, int end) {
    int & ref = dp[start][end];
    if (ref != -1) return ref;
    if (start == end) return ref = 0;
    ref = 987654321
    ;
    for (int i = start; i < end; i++) {
        int temp = arr[start] != arr[i+1];
        ref = min(ref, find(start, i) + find(i+1, end) + temp);   
    }
    return ref;
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    memset(dp, -1, sizeof dp);
    cout << find(1, N) + 1 << '\n';;
    return 0;
}