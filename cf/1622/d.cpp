#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 5e3;

int n, m;
char s[N];
LL c[N][N];
int pre[N];

int main() {
    cin >> n >> m;
    cin >> s + 1;
    **c = 1;
    for (int i = 1; i <= n; ++i) {
        *c[i] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
        pre[i] = pre[i - 1] + s[i] - '0';
    }
    if (pre[n] < m || m == 0) {
        cout << 1 << endl;
        return 0;
    }
    LL ans = 0;
    for (int i = 1, j = 1; j <= n;) {
        while (i + 1 <= n && pre[i + 1] - pre[j - 1] <= m) ++i;
        if (pre[i] - pre[j - 1] == m) {
            ans = (ans + c[i - j + 1][m] - 1) % mod;
        }
        if (pre[i] - pre[j - 1] < m) {
            break;
        }
        while (pre[i] - pre[j - 1] >= m) ++j;
    }
    for (int i = 1, j = 1; j <= n;) {
        while (i + 1 <= n && pre[i + 1] - pre[j - 1] <= m - 1) ++i;
        if (pre[i] - pre[j - 1] == m - 1 && pre[j - 1] && pre[n] - pre[i]) {
            ans = (ans - c[i - j + 1][m - 1] + 1) % mod;
        }
        if (pre[i] - pre[j - 1] < m - 1) {
            break;
        }
        while (j <= i + 1 && pre[i] - pre[j - 1] >= m - 1) ++j;
    }
    ++ans;
    ans = (ans % mod + mod) % mod;

    cout << ans << endl;

    return 0;
}