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
const int N = 3 + 44;

int n, m;
int a[N], b[N];
vector<int> edge[N];
int id[44];
int t;
int dp[N][1 << 18];

int main() {
    cin >> n >> m;
    memset(id, -1, sizeof(id));
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        if (id[b[i]] == -1) {
            id[b[i]] = 0;
        } else {
            if (!id[b[i]]) {
                id[b[i]] = ++t;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) {
        id[i] -= 1;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    memset(dp, -0x3f, sizeof(dp));
    if (id[b[1]] != -1) {
        dp[1][1 << id[b[1]]] = a[b[1]];
    } else {
        dp[1][0] = a[b[1]];
    }
    for (int x = 1; x <= n; ++x) {
        int ans = 0;
        for (int i = 0; i < 1 << t; ++i) {
            if (dp[x][i] < 0) {
                continue;
            }
            ans = max(ans, dp[x][i]);
            for (int &y : edge[x]) {
                int p = b[y];
                if (id[p] != -1) {
                    int w = id[p];
                    if (i >> w & 1) {
                        dp[y][i] = max(dp[y][i], dp[x][i]);
                    } else {
                        dp[y][i | 1 << w] = max(dp[y][i | 1 << w], dp[x][i] + a[p]);
                    }
                } else {
                    dp[y][i] = max(dp[y][i], dp[x][i] + a[p]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}