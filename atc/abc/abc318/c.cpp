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

int n, d, p, f[N];

int main() {
    cin >> n >> d >> p;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }
    LL cnt = accumulate(f + 1, f + n + 1, 0LL);
    LL ans = cnt;
    sort(f + 1, f + n + 1, greater<int>());
    int z = d;
    cnt += p;
    for (int i = 1; i <= n; ++i) {
        cnt -= f[i];
        ans = min(ans, cnt);
        --z;
        if (!z) {
            cnt += p;
            z = d;
        }
    }
    cout << ans << endl;

    return 0;
}