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
const int N = 3 + 2e6;

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
    for (int i = 1; i <= 2 * n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
}
}  // namespace SCC

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    while (m--) {
        int i, a, j, b;
        cin >> i >> a >> j >> b;
        if (a && b) {
            edge[i + n].push_back(j);
            edge[j + n].push_back(i);
        }
        if (!a && b) {
            edge[i].push_back(j);
            edge[j + n].push_back(i + n);
        }
        if (a && !b) {
            edge[i + n].push_back(j + n);
            edge[j].push_back(i);
        }
        if (!a && !b) {
            edge[i].push_back(j + n);
            edge[j].push_back(i + n);
        }
    }
    SCC::run();

    for (int i = 1; i <= n; ++i) {
        if (SCC::sccCnt[i] == SCC::sccCnt[i + n]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    cout << "POSSIBLE" << endl;
    for (int i = 1; i <= n; ++i) {
        if (SCC::sccCnt[i] < SCC::sccCnt[i + n]) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }

    return 0;
}