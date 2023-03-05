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
const int N = 3 + 1e5;

int n, a[N];
LL dp[N][2];
vector<int> edge[N];
int du[N];
LL dp2[N][2][2];
int b[N], t;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> u >> v;
        ++u;
        ++v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        ++du[u];
        ++du[v];
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (du[i] == 1) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        dp[x][1] += a[x];
        for (auto &y : edge[x]) {
            if (du[y] >= 2) {
                dp[y][0] += max(dp[x][0], dp[x][1]);
                dp[y][1] += dp[x][0];
            }
            if (--du[y] == 1) {
                q.push(y);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (du[i] == 2) {
            dp[i][1] += a[i];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (du[i] == 2) {
            int p = i;
            while (du[p]) {
                b[++t] = p;
                du[p] = 0;
                for (auto &y : edge[p]) {
                    if (du[y] == 2) {
                        p = y;
                        break;
                    }
                }
            }
            break;
        }
    }

    dp2[1][0][0] = dp[b[1]][0];
    dp2[1][1][1] = dp[b[1]][1];
    for (int i = 2; i <= t; ++i) {
        for (int j = 0; j <= 1; ++j) {
            dp2[i][0][j] = max(dp2[i - 1][1][j], dp2[i - 1][0][j]) + dp[b[i]][0];
            dp2[i][1][j] = dp2[i - 1][0][j] + dp[b[i]][1];
        }
    }
    double k;
    cin >> k;
    cout << fixed << setprecision(11) << k * max({dp2[t][0][1], dp2[t][1][0], dp2[t][0][0]}) << endl;

    return 0;
}