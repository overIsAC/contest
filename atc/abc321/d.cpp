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
const int N = 3 + 2e5;

int n, m, p, a[N], b[N];
LL pre[N];

int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    LL ans = 0;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1] + b[i];
    }

    for (int i = 1, j = m; i <= n; ++i) {
        while (j >= 1 && (LL)a[i] + b[j] > p) {
            --j;
        }
        ans += (LL)a[i] * j + pre[j];
        ans += (LL)(m - j) * p;
    }
    cout << ans << endl;

    return 0;
}