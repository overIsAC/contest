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
const int N = 3 + 2000;

int n, k;
char s[N][N];
int pre1[N][N];
int pre2[N][N];
int u[N][N], v[N][N];
int q[N], w[N];

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] + 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            pre1[i][j] = pre1[i - 1][j];
            pre2[i][j] = pre2[i][j - 1];
            if (s[i][j] == 'W') {
                ++pre1[i][j];
                ++pre2[i][j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j + k - 1 <= n; ++j) {
            int l = j, r = j + k - 1;
            if (pre2[i][n] - (pre2[i][r] - pre2[i][l - 1]) == n - k) {
                int L = max(1, i - k + 1);
                int R = i;
                ++u[L][l];
                --u[R + 1][l];
            }
            l = j;
            r = j + k - 1;
            if (pre1[n][i] - (pre1[r][i] - pre1[l - 1][i]) == n - k) {
                int L = max(1, i - k + 1);
                int R = i;
                ++v[l][L];
                --v[l][R + 1];
            }
        }
    }
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= n; ++j) {
            u[i][j] += u[i - 1][j];
            v[i][j] += v[i][j - 1];
        }
    }
    // for (int i = 1; i + k - 1 <= n; ++i) {
    //     for (int j = 1; j + k - 1 <= n; ++j) {
    //         cout << u[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // for (int i = 1; i + k - 1 <= n; ++i) {
    //     for (int j = 1; j + k - 1 <= n; ++j) {
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 1; i <= n; ++i) {
        int o = n;
        q[i] = q[i - 1];
        w[i] = w[i - 1];
        for (int j = 1; j <= n; ++j) {
            if (s[i][j] != 'W') {
                --o;
            }
        }
        if (o == n) {
            ++q[i];
        }
        o = n;
        for (int j = 1; j <= n; ++j) {
            if (s[j][i] != 'W') {
                --o;
            }
        }
        if (o == n) {
            ++w[i];
        }
    }
    int ans = q[n] + w[n];
    for (int i = 1; i + k - 1 <= n; ++i) {
        for (int j = 1; j + k - 1 <= n; ++j) {
            int lx = i, rx = min(n, i + k - 1), ly = j, ry = min(n, j + k - 1);
            int cnt = q[n] - (q[rx] - q[lx - 1]);
            cnt += w[n] - (w[ry] - w[ly - 1]);
            cnt += u[i][j];
            cnt += v[i][j];
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}