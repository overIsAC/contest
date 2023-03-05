#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 55;

int n, a[N];
set<LL> st[N][N];

bool isSqrt(LL v) {
    LL l = 1, r = 2e9;
    while (l <= r) {
        LL mid = l + r >> 1;
        if (mid * mid == v) {
            return true;
        }
        if (mid * mid > v) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int m = a[j] - a[i];
                for (int k = 1; k * k <= m; ++k) {
                    if (m % k == 0) {
                        int u = k, v = m / k;
                        if ((u - v) % 2) {
                            continue;
                        }
                        int x = (u - v) / 2, y = (u + v) / 2;
                        LL xx = (LL)x * x, yy = (LL)y * y;
                        if (a[i] - xx == a[j] - yy && a[i] <= xx && a[j] <= yy) {
                            st[i][j].insert(xx - a[i]);
                        }
                    }
                }
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                for (auto k : st[i][j]) {
                    int cnt = 0;
                    for (int q = 1; q <= n; ++q) {
                        if (isSqrt(a[q] + k)) {
                            ++cnt;
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}