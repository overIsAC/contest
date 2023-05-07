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

int n, a[N];
int f1[21][N], f2[21][N];
int _lg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        f1[0][i] = a[i];
        f2[0][i] = a[i];
    }
    _lg[2] = 1;
    for (int i = 3; i <= n; ++i) {
        _lg[i] = _lg[i / 2] + 1;
    }

    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            f1[i][j] = min(f1[i - 1][j], f1[i - 1][j + (1 << i - 1)]);
            f2[i][j] = max(f2[i - 1][j], f2[i - 1][j + (1 << i - 1)]);
        }
    }

    auto query = [&](int l, int r) -> PII {
        int t = _lg[r - l + 1];
        return {min(f1[t][l], f1[t][r - (1 << t) + 1]), max(f2[t][l], f2[t][r - (1 << t) + 1])};
    };


    auto ok = [&](int p) {
        auto u = query(1, min(p, n));
        for (int i = p + 1; i <= n; i += p) {
            int j = min(i + p - 1, n);
            auto v = query(i, j);
            if (u.second <= v.first) {
                u = v;
            } else {
                return false;
            }
        }
        return true;
    };

    int ans = 0;

    for (int i = 1; i <= n; ++i) {
        if (ok(i)) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}