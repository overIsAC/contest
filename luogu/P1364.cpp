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
const int N = 3 + 1e5;

vector<int> edge[N];
int n;
int ans, cnt;
int w[N];

void dfs(int x, int fa, int d) {
    cnt += d * w[x];
    for (auto& y : edge[x]) {
        if (y == fa) {
            continue;
        }
        dfs(y, x, d + 1);
    }
}

void addEdge(int u, int v) {
    edge[u].push_back(v);
    edge[v].push_back(u);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u, v;
        cin >> w[i] >> u >> v;
        if (u) {
            addEdge(i, u);
        }
        if (v) {
            addEdge(i, v);
        }
    }
    ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        cnt = 0;
        dfs(i, 0, 0);
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}