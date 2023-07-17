#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned LL;
#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
const int mod2 = 998244353;
const int N = 3 + 1e6;

char s[N];
ULL p1[N], p2[N], pre1[N], suf1[N], pre2[N], suf2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    p1[0] = 1;
    for (int i = 1; i < N; ++i) {
        p1[i] = p1[i - 1] * 131 % mod;
    }
    p2[0] = 1;
    for (int i = 1; i < N; ++i) {
        p2[i] = p2[i - 1] * 131 % mod2;
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> s + 1;
        int n = strlen(s + 1);
        for (int i = 1; i <= n; ++i) {
            pre1[i] = (pre1[i - 1] * 131 + s[i]) % mod;
            pre2[i] = (pre2[i - 1] * 131 + s[i]) % mod2;
        }
        suf1[n + 1] = 0;
        suf2[n + 1] = 0;
        for (int i = n; i >= 1; --i) {
            suf1[i] = (suf1[i + 1] * 131 + s[i]) % mod;
            suf2[i] = (suf2[i + 1] * 131 + s[i]) % mod2;
        }
        int L = 1, R = n;
        while (L <= R && s[L] == s[R]) {
            ++L;
            --R;
        }
        if (L > R) {
            cout << s + 1 << endl;
            continue;
        }

        auto check = [&](ULL *pre, ULL *suf, ULL *p, LL mod, int l, int r) {
            ULL u = pre[r] - pre[l - 1] * p[r - l + 1] % mod + mod;
            u %= mod;
            ULL v = suf[l] - suf[r + 1] * p[r - l + 1] % mod + mod;
            v %= mod;
            return u == v;
        };

        int u = L - 1, v = R + 1;
        for (int i = L; i <= R; ++i) {
            if (check(pre1, suf1, p1, mod, L, i) && check(pre2, suf2, p2, mod2, L, i) && u + n - v + 1 < i + n - R) {
                u = i;
                v = R + 1;
            }
            if (check(pre1, suf1, p1, mod, i, R) && check(pre2, suf2, p2, mod2, i, R) && u + n - v + 1 < L - 1 + n - i + 1) {
                u = L - 1;
                v = i;
            }
        }
        for (int i = 1; i <= u; ++i) {
            cout << s[i];
        }
        for (int i = v; i <= n; ++i) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}