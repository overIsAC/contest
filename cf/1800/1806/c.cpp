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
const int N = 3 + 4e5;

int n, a[N];

LL calc(int v) {
    LL ans = 0;
    for (int i = 1; i <= n * 2; ++i) {
        ans += abs(a[i] - v);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n * 2; ++i) {
            cin >> a[i];
        }
        if (n == 1) {
            cout << abs(a[2] - a[1]) << endl;
            continue;
        }
        LL ans = calc(0);
        if (n == 2) {
            ans = min(ans, calc(2));
        }
        if (n % 2 == 0) {
            LL cnt = calc(-1);
            int t = INT_MAX;
            for (int i = 1; i <= n * 2; ++i) {
                t = min(t, -abs(a[i] + 1) + abs(a[i] - n));
            }
            cnt += t;
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}