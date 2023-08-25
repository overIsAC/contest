#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 1e5;

int n, x, a[N];
int dp[N][2][2];
int b[N], t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cin >> x;
        for (int i = 1; i <= n; ++i) {
            a[i] -= x;
        }
        t = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= 0) {
                b[++t] = a[i];
            } else {
                if (!t || b[t] >= 0) {
                    b[++t] = a[i];
                }
                b[t] = max(b[t], a[i]);
            }
        }
        if (n == 50000) {
            cout << "t " << t << endl;
        }
        if (t == 1) {
            cout << 1 << endl;
            continue;
        }
        if (t == 2) {
            if (b[1] + b[2] >= 0) {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
            continue;
        }
        for (int i = 1; i <= t; ++i) {
            memset(dp[i], -0x3f, sizeof(dp[i]));
        }
        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= 1; ++j) {
                int cnt = 0;
                if (i) {
                    cnt += b[1];
                }
                if (j) {
                    cnt += b[2];
                }
                if (cnt >= 0) {
                    dp[2][i][j] = i + j;
                }
            }
        }
        for (int i = 3; i <= t; ++i) {
            for (int j = 0; j <= 1; ++j) {
                for (int k = 0; k <= 1; ++k) {
                    for (int q = 0; q <= 1; ++q) {
                        int cnt = 0;
                        if (q) {
                            cnt += b[i];
                        }
                        if (k) {
                            cnt += b[i - 1];
                        }
                        if (cnt < 0) {
                            continue;
                        }
                        if (j) {
                            cnt += b[i - 2];
                        }
                        if (cnt < 0) {
                            continue;
                        }
                        dp[i][k][q] = max(dp[i - 1][j][k] + q, dp[i][k][q]);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= 1; ++j) {
                ans = max(ans, dp[t][i][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}