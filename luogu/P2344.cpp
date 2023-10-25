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

const int mod = 9 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, a[N];
int b[N], t;
int pre[N];
LL dp[N];
int tr[N];

void add(int p, int v) {
    for (; p <= t; p += p & -p) {
        tr[p] += v;
        tr[p] %= mod;
    }
}

int ask(int p) {
    LL ans = 0;
    for (; p; p -= p & -p) {
        ans += tr[p];
    }
    return ans % mod;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }
    for (int i = 0; i <= n; ++i) {
        b[++t] = pre[i];
    }
    sort(b + 1, b + t + 1);
    t = unique(b + 1, b + t + 1) - b - 1;
    add(lower_bound(b + 1, b + t + 1, pre[0]) - b, 1);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(b + 1, b + t + 1, pre[i]) - b;
        dp[i] = ask(p);
        add(p, dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}