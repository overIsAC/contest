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

int n, m;
vector<int> edge[N];

namespace SCC {
int dfn[N], low[N], id;
int stk[N], ins[N], top;
int sccCnt[N], cnt;
void tarjan(int x) {
    dfn[x] = ++id;
    low[x] = id;
    stk[++top] = x;
    ins[x] = 1;
    for (auto& y : edge[x]) {
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], low[y]);
        }
    }
    if (dfn[x] == low[x]) {
        ++cnt;
        do {
            x = stk[top--];
            ins[x] = 0;
            sccCnt[x] = cnt;
        } while (dfn[x] != low[x]);
    }
}
void run() {
    for (int i = 0; i <= n * 2 - 1; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}
}  // namespace SCC

int main() {
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        edge[u].push_back(v ^ 1);
        edge[v].push_back(u ^ 1);
    }
    SCC::run();
    for (int i = 0; i < 2 * n; i += 2) {
        if (SCC::sccCnt[i] == SCC::sccCnt[i + 1]) {
            cout << "NIE" << endl;
            return 0;
        }
    }
    vector<int> ans;
    for (int i = 0; i < 2 * n; i += 2) {
        if (SCC::sccCnt[i] < SCC::sccCnt[i + 1]) {
            ans.push_back(i + 1);
        } else {
            ans.push_back(i + 2);
        }
    }
    for (auto& i : ans) {
        cout << i << endl;
    }
    return 0;
}