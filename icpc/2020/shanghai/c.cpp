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
const int N = 3 + 30;

int a[N], b[N];

LL cnt[N][2][2][2], dp[N][2][2][2];
bool vis[N][2][2][2];

pair<LL, LL> dfs(int p, int lead, int limita, int limitb) {
    if (!p) {
        return {0, 1};
    }
    if (vis[p][lead][limita][limitb]) {
        return {dp[p][lead][limita][limitb], cnt[p][lead][limita][limitb]};
    }
    LL u = 0, v = 0;
    int upa = limita ? a[p] : 1;
    int upb = limitb ? b[p] : 1;
    for (int i = 0; i <= upa; ++i) {
        for (int j = 0; j <= upb; ++j) {
            if (i & j) {
                continue;
            }
            auto o = dfs(p - 1, lead && i + j == 0, limita && (i == upa), limitb && (j == upb));
            if (lead && i + j) {
                o.first = o.second * p;
            }
            u += o.first;
            v += o.second;
        }
    }
    u %= mod;
    v %= mod;
    vis[p][lead][limita][limitb] = 1;
    dp[p][lead][limita][limitb] = u;
    cnt[p][lead][limita][limitb] = v;
    return {dp[p][lead][limita][limitb], cnt[p][lead][limita][limitb]};
}

void solve() {
    int x, y;
    cin >> x >> y;
    int lena = 0;
    int lenb = 0;
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    do {
        a[++lena] = x % 2;
        x /= 2;
    } while (x);
    do {
        b[++lenb] = y % 2;
        y /= 2;
    } while (y);
    memset(vis, 0, sizeof(vis));
    cout << dfs(max(lena, lenb), 1, 1, 1).first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}