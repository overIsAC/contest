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
const int N = 3 + 6e5;

unsigned f[20][N];
int n, m;
int lg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> f[0][i];
    }
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            f[i][j] = __gcd(f[i - 1][j], f[i - 1][j + (1 << i - 1)]);
        }
    }

    auto query = [&](int l, int r) {
        int t = lg[r - l + 1];
        return __gcd(f[t][l], f[t][r - (1 << t) + 1]);
    };

    while (m--) {
        int l, r;
        cin >> l >> r;
        int p = r;
        int ans = 0;
        while (p >= l) {
            int L = l, R = p;
            unsigned g = query(p, r);
            while (L < R) {
                int mid = L + R >> 1;
                if (query(mid, r) == g) {
                    R = mid;
                } else {
                    L = mid + 1;
                }
            }
            ++ans;
            p = R - 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
