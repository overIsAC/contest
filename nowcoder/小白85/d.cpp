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
const int N = 3 + 1e6;

int n, m, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int now = m, can = 0;
    LL ans = 0;
    for (int i = 2; i <= n; ++i) {
        --now;
        ++ans;
        if (now < 0) {
            now += can;
            ans += can;
            if (now < 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
        if (a[i] == 0) {
            can = m - now;
        } else {
            now -= a[i];
            if (now < 0) {
                now += can;
                ans += can;
                if (now < 0) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}