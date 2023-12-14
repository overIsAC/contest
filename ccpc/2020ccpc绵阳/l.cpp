#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x)                                                             \
    cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " \
         << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 3e6;

int n;
PII a[N];

LL qpow(LL q, LL n) {
    LL ans = 1;
    while (n) {
        if (n & 1) ans = ans * q % mod;
        q = q * q % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, Case = 0;
    cin >> T;
    while (T--) {
        cout << "Case #" << ++Case << ": ";

        cin >> n;
        mp.clear();
        for (int i = 1; i <= n; ++i) {
            int a, x;
            cin >> a >> x;
            mp[a] = x;
        }
        for (auto &i : mp) {
            int v = i.second / 2;
            if (i.second % 2 == 0) {
                --v;
            }
            if (v > 0) {
                i.second -= v * 2;
                mp[i.first + 1] += v;
            }
        }
        int t = 0;
        for (auto &i : mp) {
            a[++t] = i;
        }
        LL ans = 1;
        for (int i = 1; i <= t; ++i) {
            int j = i;
            while (j + 1 <= t && a[j + 1].first == a[j].first + 1) {
                ++j;
            }
            LL cnt = qpow(2, j - i + 1);
            for (int k = j; k >= i; --k) {
                if (a[k].second == 2) {
                    cnt += qpow(2, k - i);
                }
            }
            cnt %= mod;
            ans = ans * cnt % mod;

            i = j;
        }
        cout << ans << endl;
    }
    return 0;
}