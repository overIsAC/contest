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

int n;
LL m;
PII a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i].second;
        }
        sort(a + 1, a + n + 1);
        for (int i = n - 1; i > 0; --i) {
            a[i].second = min(a[i + 1].second, a[i].second);
        }
        LL d = m;
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            while (d >= a[i].first && i <= n) {
                ++i;
            }
            if (i > n) {
                break;
            }
            m -= a[i].second;
            while (m > 0 && d < a[i].first) {
                d += m;
                if (d >= a[i].first) {
                    break;
                }
                m -= a[i].second;
            }
            if (d < a[i].first) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}