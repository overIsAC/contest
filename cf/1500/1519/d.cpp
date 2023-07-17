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
const int N = 3 + 5000;

LL r[N][N];
LL pre[N], suf[N];
int n, a[N], b[N];

void dfs(int L, int R) {
    if (r[L][R] || L > R) {
        return;
    }
    dfs(L + 1, R - 1);
    r[L][R] = r[L + 1][R - 1] + (LL)a[L] * b[R];
    if (L != R) {
        r[L][R] += (LL)a[R] * b[L];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = (LL)a[i] * b[i] + pre[i - 1];
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = (LL)a[i] * b[i] + suf[i + 1];
    }
    LL ans = pre[n];
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dfs(i, j);
            ans = max(ans, pre[i - 1] + r[i][j] + suf[j + 1]);
        }
    }
    cout << ans << endl;

    return 0;
}