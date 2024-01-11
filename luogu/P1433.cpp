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
const int N = 3 + 22;

int n;
double x[N], y[N];
double ans = 1e18;
int vis[N];
double d[N][N];
clock_t be;

double calcDist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void dfs(int p, int cnt, double nowDist) {
    if (nowDist >= ans) {
        return;
    }
    if (cnt == n) {
        ans = nowDist;
        return;
    }
    if (1.0 * (clock() - be) / CLOCKS_PER_SEC > 1) {
        cout << fixed << setprecision(2) << ans << endl;
        exit(0);
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i]) {
            continue;
        }
        vis[i] = 1;
        dfs(i, cnt + 1, nowDist + d[p][i]);
        vis[i] = 0;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            d[i][j] = calcDist(x[i], y[i], x[j], y[j]);
        }
    }

    be = clock();
    dfs(0, 0, 0);

    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}