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
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 2e5;

int n, m;
int a[N];

int f[N];
int p[N], t;

int main() {
    for (int i = 2; i < N; ++i) {
        if (f[i])
            continue;
        p[++t] = i;
        for (int j = i + i; j < N; j += i) {
            f[j] = 1;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (a[i] % a[i + 1]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << 0 << endl;
            continue;
        }

        LL ans = 1;
        for (int i = n; i > 1; --i) {
            int xy = a[i - 1] / a[i];
            vector<int> ve;
            int xxyy = xy;
            for (int i = 1; i <= t && p[i] * p[i] <= xxyy && p[i] <= xy; ++i) {
                while (xy % p[i] == 0) {
                    ve.push_back(p[i]);
                    xy /= p[i];
                }
            }
            if (xy > 1) {
                ve.push_back(xy);
            }
            sort(ve.begin(), ve.end());
            ve.erase(unique(ve.begin(), ve.end()), ve.end());
            LL temp = m / a[i];
            for (int j = 1; j < (1 << ve.size()); ++j) {
                int c = 0;
                LL mul = 1;
                for (int k = 0; k < ve.size(); ++k) {
                    if (j >> k & 1) {
                        ++c;
                        mul *= ve[k];
                    }
                }
                if (c & 1) {
                    temp -= m / a[i] / mul;
                } else {
                    temp += m / a[i] / mul;
                }
                temp %= mod;
            }
            temp = (temp % mod + mod) % mod;
            ans = ans * temp % mod;
        }
        cout << ans << endl;
    }

    return 0;
}