#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 13;

int n, m;
int a[N];
int d[N][N];
int dp[1 << N][N][N];
LL cnt[1 << N][N][N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        memset(d, 0, sizeof(d));
        while (m--) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            d[u][v] = 1;
            d[v][u] = 1;
        }
        memset(dp, -0x3f, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                if (!d[i][j]) {
                    continue;
                }
                dp[(1 << i) | (1 << j)][i][j] = a[i] + a[j] + a[i] * a[j];
                cnt[(1 << i) | (1 << j)][i][j] = 1;
            }
        }
        for (int i = 1; i < 1 << n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!(i >> j & 1)) {
                    continue;
                }
                for (int k = 0; k < n; ++k) {
                    if (!(i >> k & 1)) {
                        continue;
                    }
                    if (!d[j][k]) {
                        continue;
                    }
                    for (int q = 0; q < n; ++q) {
                        if (!(i >> q & 1)) {
                            continue;
                        }
                        if (!d[k][q]) {
                            continue;
                        }
                        int w = a[q];
                        w += a[k] * a[q];
                        if (d[j][q]) {
                            w += a[j] * a[k] * a[q];
                        }
                        if (dp[i][k][q] < dp[i ^ (1 << q)][j][k] + w) {
                            dp[i][k][q] = dp[i ^ (1 << q)][j][k] + w;
                            cnt[i][k][q] = cnt[i ^ (1 << q)][j][k];
                        } else if (dp[i][k][q] == dp[i ^ (1 << q)][j][k] + w) {
                            cnt[i][k][q] += cnt[i ^ (1 << q)][j][k];
                        }
                    }
                }
            }
        }
        int mx = -1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                mx = max(dp[(1 << n) - 1][i][j], mx);
            }
        }
        if (mx < 0) {
            cout << "0 0" << endl;
            continue;
        }
        LL c = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mx == dp[(1 << n) - 1][i][j]) {
                    c += cnt[(1 << n) - 1][i][j];
                }
            }
        }
        cout << mx << ' ' << c / 2 << endl;
    }
    return 0;
}