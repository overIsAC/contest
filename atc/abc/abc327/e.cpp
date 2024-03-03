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
const int N = 3 + 5000;

double pw[N];
double sq[N];
int n, p[N];
double dp[N][N], pre[N][N];

int ok(double x) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = pre[i - 1][j - 1] * 0.9 + p[i];
            pre[i][j] = max(pre[i - 1][j], dp[i][j]);

            if (dp[i][j] >= (x + 1200 / sq[j]) * 10 * (1 - pw[j])) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = pw[i - 1] * 0.9;
        sq[i] = sqrt(i);
    }
    for (int i = 0; i <= n; ++i) {
        pre[i][0] = 0;
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            dp[i][j] = -1e9;
        }
    }

    double l = -1e9, r = 1e9;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (ok(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << fixed << setprecision(10) << r << endl;

    return 0;
}