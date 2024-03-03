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
const int N = 3 + 5e5;

int n, m;
int a[N];
vector<int> edge[N];

int dfn[N], low[N], stk[N], ins[N], id, top;
int color[N];

int num;
vector<int> newEdge[N];
int du[N];  // 度数
LL ans = 4e9;
LL d[N];

void tarjan(int x) {
    stk[++top] = x;  // stack
    ins[x] = 1;      // in stack
    dfn[x] = ++id;
    low[x] = id;

    for (auto& y : edge[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], low[y]);
        }
    }
    if (dfn[x] == low[x]) {
        int y;
        ++num;
        int size = 0;
        do {
            y = stk[top--];
            ins[y] = 0;

            color[y] = num;

            ++size;
        } while (y != x);
        if (size >= 2) {
            ans = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }

    memset(d, 0x3f, sizeof(d));
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!du[i]) {
            q.push(i);
        }
    }
    while (q.size()) {
        int x = q.front();
        q.pop();
        ans = min(ans, d[x] + a[x]);
        for (auto& y : edge[x]) {
            if (!--du[y]) {
                q.push(y);
            }
            d[y] = min(d[y], min<LL>(a[x], d[x]));
        }
    }

    sort(a + 1, a + n + 1);
    ans = min(ans, 2LL * (a[1] + a[2]));
    cout << ans << endl;

    return 0;
}
