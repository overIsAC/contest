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

int n, m, q;
int w[N];
int d[101][N];
vector<int> edge[N];

void bfs(int* d, int rank) {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (w[i] <= rank) {
            q.push(i);
            d[i] = 0;
        }
    }
    while (q.size()) {
        auto x = q.front();
        q.pop();
        for (auto& y : edge[x]) {
            if (d[y] > d[x] + 1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= 100; ++i) {
        bfs(d[i], i);
    }
    while (q--) {
        int p, z;
        cin >> p >> z;
        int ans = d[z][p];
        if (ans > n) {
            ans = -1;
        }
        cout << ans << endl;
    }
}

int main() {
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}