#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 1e6;

int n, k;
vector<int> a[N];
int b[N], t;

int tr[N];

void add(int *tr, int p, int v) {
    for (; p <= t; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int *tr, int p) {
    if (p <= 0) return 0;
    int ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0, m; i < n; ++i) {
        scanf("%d", &m);
        a[i].resize(m);
        for (auto &j : a[i]) {
            scanf("%d", &j);
            b[++t] = j;
        }
    }
    sort(b + 1, b + t + 1);
    t = unique(b + 1, b + t + 1) - b - 1;

    LL ans = 0;
    for (int i = 0; i < n; ++i) {
        for (auto &j : a[i]) {
            int p = lower_bound(b + 1, b + t + 1, k - j) - b;
            ans += ask(tr, t) - ask(tr, p - 1);
            ans %= mod;
        }
        for (auto &j : a[i]) {
            int p = lower_bound(b + 1, b + t + 1, j) - b;
            add(tr, p, 1);
        }
    }
    cout << ans << endl;

    return 0;
}