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

int n, q[N], a[N], b[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> q[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 0; i <= 1e6; ++i) {
        int ok = 1;
        int cnt = 1e9;
        for (int j = 1; j <= n; ++j) {
            if (a[j] * i <= q[j]) {
                if (b[j] == 0) {
                    continue;
                }
                cnt = min((q[j] - a[j] * i) / b[j], cnt);
            } else {
                ok = 0;
                break;
            }
        }
        if (ok) {
            ans = max(ans, i + cnt);
        } else {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}