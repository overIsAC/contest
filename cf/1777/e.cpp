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

struct Edge {
    int u, v, w;
} e[N];

vector<int> edge[N];
int n, m;
int dfn[N], stk[N], top, ins[N], low[N], id;
int scc[N], sid;
int du[N];

void tarjan(int x) {
    dfn[x] = ++id;
    low[x] = id;
    ins[x] = 1;
    stk[++top] = x;
    for (int &y : edge[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } 
        if (ins[y]) {
            low[x] = min(low[x], low[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        ++sid;
        do {
            y = stk[top--];
            ins[y] = 0;
            scc[y] = sid;
        } while (y != x);
    }
}

int ok(int w) {
    for (int i = 1; i <= m; ++i) {
        edge[e[i].u].push_back(e[i].v);
        if (e[i].w <= w) {
            edge[e[i].v].push_back(e[i].u);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int x = 1; x <= n; ++x) {
        for (int &y : edge[x]) {
            if (scc[x] == scc[y]) {
                continue;
            }
            ++du[scc[y]];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= sid; ++i) {
        if (du[i] == 0) {
            ++cnt;
        }
    }

    for (int i = 1; i <= n; ++i) {
        edge[i].clear();
        dfn[i] = ins[i] = low[i] = scc[i] = 0;
        du[i] = 0;
    }
    top = id = sid = 0;

    return cnt == 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> e[i].u >> e[i].v >> e[i].w;
        }
        int l = 0, r = 1e9;
        while (l < r) {
            int mid = l + r >> 1;
            if (ok(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (ok(r)) {
            cout << r << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}