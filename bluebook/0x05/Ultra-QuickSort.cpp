#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 3 + 5e5;

int n, a[N], b[N];
LL ans;

void sort(int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + r >> 1;
    sort(l, mid);
    sort(mid + 1, r);
    int u = l, v = mid + 1, w = l;
    while (u <= mid && v <= r) {
        if (a[u] <= a[v]) {
            b[w++] = a[u++];
        } else {
            b[w++] = a[v++];
            ans += mid - u + 1;
        }
    }
    while (u <= mid) {
        b[w++] = a[u++];
    }
    while (v <= r) {
        b[w++] = a[v++];
    }
    for (int i = l; i <= r; ++i) {
        a[i] = b[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n, n) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        ans = 0;
        sort(1, n);
        cout << ans << endl;
    }

    return 0;
}