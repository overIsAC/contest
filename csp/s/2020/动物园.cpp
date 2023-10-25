#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned long long;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#else
#define db(x)
#endif

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e6;

int n, m, c, k;
ULL a[N];
int p[N], q[N];
int vis1[N], vis2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> c >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> p[i] >> q[i];
    }
    for (int i = 1; i <= m; ++i) {
        vis1[p[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            if (vis1[j] && (a[i] >> j & 1)) {
                vis2[j] = 1;
            }
        }
    }
    ULL ans = 1;
    for (int j = 0; j < k; ++j) {
        if (vis1[j]) {
            if (vis2[j]) {
                ans *= 2;
            }
        } else {
            ans *= 2;
        }
    }
    ans -= n;

    if (n == 0 && k == 64 && m == 0) {
        cout << "18446744073709551616" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}