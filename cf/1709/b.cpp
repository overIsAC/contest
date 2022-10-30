#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, m;
int a[N];
LL pre[N], suf[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; ++i) {
        pre[i] = pre[i - 1];
        if (a[i] < a[i - 1]) {
            pre[i] += a[i - 1] - a[i];
        }
    }
    suf[n + 1] = 0;
    for (int i = n - 1; i; --i) {
        suf[i] = suf[i + 1];
        if (a[i] < a[i + 1]) {
            suf[i] += a[i + 1] - a[i];
        }
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if (l <= r) {
            cout << pre[r] - pre[l] << endl;
        } else {
            cout << suf[r] - suf[l] << endl;
        }
    }
    return 0;
}