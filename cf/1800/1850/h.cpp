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
const int N = 3 + 2e5;

int n, m;
vector<PII> edge[N];
LL d[N];
int vis[N];

void dfs(int x) {
    vis[x] = 1;
    for (auto [y, w] : edge[x]) {
        if (vis[y]) {
            continue;
        }
        d[y] = d[x] + w;
        dfs(y);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            edge[i].clear();
            vis[i] = 0;
        }
        while (m--) {
            int a, b, d;
            cin >> a >> b >> d;
            edge[a].push_back({b, d});
            edge[b].push_back({a, -d});
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[i]) {
                continue;
            }
            dfs(i);
        }
        int ok = 1;
        for (int x = 1; x <= n; ++x) {
            for (auto [y, w] : edge[x]) {
                if (d[y] != d[x] + w) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) {
                break;
            }
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}