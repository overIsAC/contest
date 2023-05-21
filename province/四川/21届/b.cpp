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
const int N = 3 + 1e6;

vector<PII> edge[N];
int n, m, k, s, t;
int d[N];

int bfs(int v) {
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == t) {
            return 1;
        }
        for (auto [y, w] : edge[x]) {
            if (w < v) {
                continue;
            }
            if (d[y]) {
                continue;
            }
            d[y] = 1;
            q.push(y);
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s >> t >> k;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }
    int l = 0, r = k;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (bfs(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    if (!bfs(r)) {
        r = 0;
    }
    cout << r << endl;
    return 0;
}