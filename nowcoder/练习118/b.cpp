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
const int N = 3 + 1e6;

int n, a[N], k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    unsigned long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += (LL)__gcd(a[i], k) * (n - 1);
        ans += __gcd<LL>((LL)a[i] * a[i], k) / __gcd(a[i], k);
    }
    cout << ans << endl;

    return 0;
}