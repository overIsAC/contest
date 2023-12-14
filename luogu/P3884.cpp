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
const int N = 3 + 111;

vector<PII> edge[N];
int n;
int w[N];  // 宽度
int d[N];
int maxDepth, maxWidth;
int x, y;

void dfs(int x, int fa, int dep) {
    maxDepth = max(dep, maxDepth);

    ++w[dep];
    maxWidth = max(maxWidth, w[dep]);

    for (auto& e : edge[x]) {
        int y = e.first, w = e.second;
        if (y == fa) {
            continue;
        }
        dfs(y, x, dep + 1);
    }
}

void dfs2(int x, int fa) {
    for (auto& e : edge[x]) {
        int y = e.first, w = e.second;
        if (y == fa) {
            continue;
        }
        d[y] = d[x] + w;
        dfs2(y, x);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back({v, 1});
        edge[v].push_back({u, 2});
    }
    cin >> x >> y;

    dfs(1, 0, 1);

    cout << maxDepth << endl;
    cout << maxWidth << endl;

    dfs2(x, 0);
    cout << d[y] << endl;

    return 0;
}