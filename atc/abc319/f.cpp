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

// const int mod = 7 + 1e9;
const int mod = 998244353;
const int N = 3 + 555;

vector<int> edge[N];
vector<int> p;
int n, t[N], s[N], g[N];
LL dp[2055];
int fa[N];

void f(int st) {
    vector<int> vis(n + 1);
    vector<int> q;
    q.push_back(1);
    vis[1] = 1;

    for (int i = 0; i < p.size(); ++i) {
        if (st >> i & 1) {
            int t = p[i];
            while (t && !vis[t]) {
                q.push_back(t);
                vis[t] = 1;
                t = fa[t];
            }
        }
    }

    LL cnt = dp[st];
    if (cnt < 0) {
        return;
    }
    if (cnt > 1e9) {
        cout << "Yes" << endl;
        exit(0);
    }

    while (q.size()) {
        sort(q.begin(), q.end(), [&](int a, int b) { return s[a] > s[b]; });
        int x = q.back();
        if (s[x] > cnt) {
            break;
        }
        q.pop_back();

        vis[x] = 1;

        for (auto& y : edge[x]) {
            if (vis[y]) {
                continue;
            }
            if (t[y] == 1) {
                q.push_back(y);
            }
        }
    }

    int ok = 1;
    for (int i = 2; i <= n; ++i) {
        if (t[i] == 1) {
            if (!vis[i]) {
                ok = 0;
                break;
            }
        }
    }
    if (ok) {
        cout << "Yes" << endl;
        exit(0);
    }

    auto update = [&](LL& ndp, LL cnt, vector<int> q) {
        vector<int> vis2(n + 1);
        while (q.size()) {
            sort(q.begin(), q.end(), [&](int a, int b) { return s[a] > s[b]; });
            int x = q.back();
            if (s[x] > cnt) {
                break;
            }
            q.pop_back();

            if (vis2[x]) {
                continue;
            }
            vis2[x] = 1;

            if (t[x] == 1) {
                cnt += g[x];
            }

            for (auto& y : edge[x]) {
                if (vis[y]) {
                    continue;
                }
                if (t[y] == 1) {
                    q.push_back(y);
                }
            }
        }
        ndp = max(ndp, cnt);
    };

    for (int i = 0; i < p.size(); ++i) {
        if (st >> i & 1) {
            continue;
        }
        int connect = 0;
        for (auto& y : edge[p[i]]) {
            if (vis[y]) {
                connect = 1;
                break;
            }
        }
        if (connect) {
            cnt *= g[p[i]];
            q.push_back(p[i]);
            vis[p[i]] = 1;

            update(dp[st | (1 << i)], cnt, q);

            cnt /= g[p[i]];
            q.pop_back();
            vis[p[i]] = 0;
        }
    }
}

void dfs(int x, int fa) {
    ::fa[x] = fa;
    for (auto& y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x);
    }
}

int main() {
#if LEMON
    freopen("D:\\acidlemon\\contest\\atc\\abc319\\f.in", "r", stdin);
#endif

    cin >> n;

    for (int i = 2; i <= n; ++i) {
        int u, v;
        u = i;
        cin >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);

        cin >> t[i] >> s[i] >> g[i];

        if (t[i] == 2) {
            p.push_back(i);
        }
    }

    dfs(1, 0);

    memset(dp, -0x3f, sizeof(dp));
    auto update = [&]() {
        vector<int> q;
        q.push_back(1);
        LL cnt = 1;
        vector<int> vis(n + 1);
        vis[1] = 1;
        while (q.size()) {
            sort(q.begin(), q.end(), [&](int a, int b) { return s[a] > s[b]; });
            int x = q.back();
            q.pop_back();

            if (s[x] > cnt) {
                break;
            }

            vis[x] = 1;

            cnt += g[x];

            for (auto& y : edge[x]) {
                if (vis[y]) {
                    continue;
                }
                if (t[y] == 1) {
                    q.push_back(y);
                }
            }
        }
        dp[0] = cnt;
    };
    update();

    for (int i = 0; i < 1 << p.size(); ++i) {
        f(i);
    }
    cout << "No" << endl;

    return 0;
}