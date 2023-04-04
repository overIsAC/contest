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

int n, m;
int a[N], b[N], c[N];
int k[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> k[i];
        }
        for (int i = 1; i <= m; ++i) {
            cin >> a[i] >> b[i] >> c[i];
        }
        sort(k + 1, k + n + 1);

        auto check = [&](LL a, LL b, LL c) {
            return b * b < 4LL * a * c;
        };

        for (int i = 1; i <= m; ++i) {
            auto p = lower_bound(k + 1, k + n + 1, b[i]) - k;
            if (1 <= p && p <= n && check(a[i], b[i] - k[p], c[i])) {
                cout << "YES" << endl;
                cout << k[p] << endl;
                continue;
            }
            --p;
            if (1 <= p && p <= n && check(a[i], b[i] - k[p], c[i])) {
                cout << "YES" << endl;
                cout << k[p] << endl;
                continue;
            }
            cout << "NO" << endl;
        }
    }
    return 0;
}