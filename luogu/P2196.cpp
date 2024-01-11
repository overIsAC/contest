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
const int N = 3 + 333;

int n, a[N];
int w[N][N];

int d[N];
int ne[N];

int dfs(int x) {
    if (d[x] >= 0) {
        return d[x];
    }
    d[x] = a[x];
    for (int y = x + 1; y <= n; ++y) {
        if (w[x][y]) {
            int z = dfs(y);
            d[x] = max(d[x], z + a[x]);
            if (d[x] == z + a[x]) {
                ne[x] = y;
            }
        }
    }
    return d[x];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            cin >> w[i][j];
        }
    }
    memset(d, -0x3f, sizeof(d));
    int x = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        int z = dfs(i);
        ans = max(ans, z);
        if (z == ans) {
            x = i;
        }
    }
    while (x) {
        cout << x << ' ';
        x = ne[x];
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}