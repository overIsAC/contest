#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using ULL = unsigned long long;

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
const int N = 3 + 1e3;

int n, q;
char s[N][N];
LL pre[N][N];

LL calc(int u, int v) {
    if (u < 0 || v < 0) {
        return 0;
    }
    LL ans = (LL)(u / n) * (v / n) * pre[n - 1][n - 1];

    ans += (LL)(v / n) * pre[u % n][n - 1];
    ans += (LL)(u / n) * pre[n - 1][v % n];
    ans += pre[u % n][v % n];

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == 'B') {
                ++pre[i][j];
            }
            if (i >= 1) {
                pre[i][j] += pre[i - 1][j];
            }
            if (j >= 1) {
                pre[i][j] += pre[i][j - 1];
            }
            if (i >= 1 && j >= 1) {
                pre[i][j] -= pre[i - 1][j - 1];
            }
        }
    }

    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << calc(c, d) - calc(c, b - 1) - calc(a - 1, d) +
                    calc(a - 1, b - 1)
             << endl;
    }
    return 0;
}