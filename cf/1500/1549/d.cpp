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
const int N = 3 + 2e5;

int n, m;
LL a[N];
LL b[N];

LL f[N][20];
int lg[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    lg[1] = 0;
    for (int i = 2; i < N; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i < n; ++i) {
            f[i][0] = abs(a[i] - a[i + 1]);
        }
        m = n - 1;
        for (int j = 1; j < 20; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= m; ++i) {
                f[i][j] = __gcd(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
            }
        }
        int ans = 1;
        auto query = [&](int l, int r) {
            int g = lg[r - l + 1];
            return __gcd(f[l][g], f[r - (1 << g) + 1][g]);
        };
        for (int i = 1; i <= m; ++i) {
            if (f[i][0] == 1) {
                continue;
            }
            int l = i, r = m;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                if (query(i, mid) > 1) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            ans = max(r - i + 2, ans);
        }
        cout << ans << endl;
    }
    return 0;
}

/**
7
4 9 4 4 8 8 8


 *
 */