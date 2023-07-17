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

int n, k, x;
int a[N], pre[N], suf[N];

int main() {
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] | a[i];
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = suf[i + 1] | a[i];
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        LL t = a[i];
        for (int j = 1; j <= k; ++j) {
            t *= x;
        }
        t |= pre[i - 1] | suf[i + 1];
        ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}