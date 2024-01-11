#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n;
PII a[N];
int b[N], t;
int tr[N];

void add(int p, int v) {
    for (; p <= t; p += p & -p) {
        tr[p] += v;
    }
}

int ask(int p) {
    int ans = 0;
    for (; p >= 1; p -= p & -p) {
        ans += tr[p];
    }
    return ans;
}

void solve() {
    cin >> n;
    t = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].first >> a[i].second;
        b[++t] = a[i].second;
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + t + 1);
    t = unique(b + 1, b + t + 1) - b - 1;

    for (int i = 1; i <= n; ++i) {
        tr[i] = 0;
    }

    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(b + 1, b + t + 1, a[i].second) - b;
        ans += ask(t) - ask(p);
        add(p, 1);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}