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
const int N = 3 + 1e5;

int n, d, v[N], a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    for (int i = 1; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LL p = 0;  // 剩下的距离
    LL ans = 0;
    LL minv = 1e18;
    for (int i = 1; i < n; ++i) {
        minv = min<LL>(minv, a[i]);
        p -= v[i];
        if (p >= 0) {
            continue;
        }
        p = -p;
        LL oil = (p + d - 1) / d;  // 要加的油量
        ans += oil * minv;
        p = oil * d - p;
    }
    cout << ans << endl;
    return 0;
}