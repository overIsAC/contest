#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

#define lson (k << 1)
#define rson (k << 1 | 1)
#if LEMON
#define db(x) cout << "function " << __FUNCTION__ << ", line " << __LINE__ << " : " << #x << " " << x << endl;
#define dbf(func) func();
#else
#define db(x)
#define dbf(func)
#endif

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const int mod = 7 + 1e9;
// const int mod = 998244353;
const int N = 3 + 200;

int n;
int x[N], y[N], p[N];
bool vis[N];

void dfs(int x, LL v) {
    if (vis[x]) {
        return;
    }
    vis[x] = 1;
    for (int y = 1; y <= n; ++y) {
        if (p[x] * v >= abs<LL>(::x[x] - ::x[y]) + abs<LL>(::y[x] - ::y[y])) {
            dfs(y, v);
        }
    }
}

bool ok(LL v) {
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        dfs(i, v);
        bool ok = true;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i] >> p[i];
    }
    LL l = 0, r = 4e9;
    while (l < r) {
        LL mid = l + r >> 1;
        if (ok(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << r << endl;
    return 0;
}
