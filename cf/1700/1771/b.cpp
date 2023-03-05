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

int n, m;
PII a[N];
int mn[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> a[i].first >> a[i].second;
            if (a[i].first > a[i].second) {
                swap(a[i].first, a[i].second);
            }
        }
        sort(a + 1, a + m + 1);
        mn[m] = a[m].second;
        for (int i = m - 1; i > 0; --i) {
            mn[i] = min(mn[i + 1], a[i].second);
        }
        LL ans = 0;
        int p = 1;
        for (int i = 1; i <= n; ++i) {
            while (p <= m && a[p].first < i) {
                ++p;
            }
            if (p <= m) {
                ans += mn[p] - i;
            } else {
                ans += n - i + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}