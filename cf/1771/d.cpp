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
const int N = 3 + 2e3;

int n;
char s[N];
vector<int> edge[N];
int d[N][N];
int dp[N][N];

void bfs(int x, int *d) {
    for (int i = 1; i <= n; ++i) {
        d[i] = 1e9;
    }
    d[x] = 0;
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (auto &y : edge[x]) {
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
}

bool check(const vector<int> &a) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 4; ++j) {
            for (int q = i; q <= j; ++q) {
                if (d[a[i]][a[j]] < d[a[i]][a[q]] ||
                    d[a[i]][a[j]] < d[a[q]][a[j]]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int dfs(int x, int y) {
    if (x > y) {
        swap(x, y);
    }
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    dp[x][y] = 1;
    if (x == y) {
        return 1;
    }
    if (s[x] == s[y]) {
        dp[x][y] = 2;
    }
    if (d[x][y] <= 1) {
        return dp[x][y];
    }
    for (auto &xx : edge[x]) {
        if (d[x][y] <= d[xx][y]) {
            continue;
        }
        dp[x][y] = max(dp[x][y], dfs(xx, y));
    }
    for (auto &yy : edge[y]) {
        if (d[x][y] <= d[x][yy]) {
            continue;
        }
        dp[x][y] = max(dp[x][y], dfs(x, yy));
    }
    for (auto &xx : edge[x]) {
        for (auto &yy : edge[y]) {
            if (check({x, xx, yy, y})) {
                if (s[x] == s[y]) {
                    dp[x][y] = max(dp[x][y], dfs(xx, yy) + 2);
                } else {
                    dp[x][y] = max(dp[x][y], dfs(xx, yy));
                }
            }
        }
    }
    return dp[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s + 1;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i) {
            bfs(i, d[i]);
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = -1;
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                ans = max(ans, dfs(i, j));
            }
        }
        cout << ans << endl;
    }

    return 0;
}