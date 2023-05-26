#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 2e5;

int n, a, m;
PII b[N];
int t;
LL pre[N];

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        n >>= 1;
        q = q * q % mod;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            ++mp[a];
        }
        t = 0;
        for (auto &i : mp) {
            b[++t] = i;
        }
        pre[0] = 1;
        for (int i = 1; i <= t; ++i) {
            pre[i] = pre[i - 1] * b[i].second % mod;
        }
        LL ans = 0;
        for (int i = m; i <= t; ++i) {
            if (b[i].first - b[i - m + 1].first + 1 == m) {
                ans += pre[i] * qpow(pre[i - m], mod - 2);
                ans %= mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}